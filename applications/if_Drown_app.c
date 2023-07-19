/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-07-09     Y9000P       the first version
 */
#include <rt_ai_network_model.h>
#include <rt_ai.h>
#include <rt_ai_log.h>
#include <math.h>
#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"

typedef struct imginfo{
    int width;
    int height;
    unsigned char* img;
} imginfo;

#define SCALING_X 6.4
#define SCALING_Y 4.8
static rt_ai_t model = NULL;

rt_uint8_t img_Gray[240][320] = {0};
rt_uint8_t *img_Gray_p = &img_Gray[0][0];
imginfo img = {320,240,&img_Gray[0][0]};

void ai_run_complete(void* arg)
{
    *(int*)arg = 1;
}

void Bilinear_interpolation_algorithm(rt_uint8_t array_in_320X240[][320],rt_uint8_t array_out_50X50[][50])
{
    rt_uint16_t i_in,j_in,i_out,j_out;
    float Px,Py;
    float R2,R1;
    for(j_out=0;j_out<50;j_out++)
    {
        Py=((float)j_out+0.5)*SCALING_Y-0.5;//计算纵坐标
        j_in=(rt_uint16_t)Py;
        //经计算320*240->50*50不需要判断边界
        for(i_out=0;i_out<50;i_out++)
        {
            Px=((float)i_out+0.5)*SCALING_X-0.5;
            i_in=(rt_uint16_t)(((float)i_out+0.5)*SCALING_X-0.5);//计算横坐标
            R2=((float)i_in+1.0-Px)*array_in_320X240[j_in][i_in]+(Px-i_in)*array_in_320X240[j_in][i_in+1];//计算R2的灰度值
            R1=((float)i_in+1.0-Px)*array_in_320X240[j_in+1][i_in]+(Px-i_in)*array_in_320X240[j_in+1][i_in+1];
            array_out_50X50[j_out][i_out]=(rt_uint16_t)((Py-j_in)*R1+(j_in+1-Py)*R2);
        }
    }
}

int if_Drown(rt_uint8_t array_in_320X240[][320])
{
    rt_uint8_t array_out_50X50[50][50] = {0};
    rt_int8_t array_out_50X50_i[50][50] = {0};

    Bilinear_interpolation_algorithm(array_in_320X240,array_out_50X50);

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            array_out_50X50_i[i][j] = (rt_int8_t)((rt_int16_t)array_out_50X50[i][j] - 128);
        }
    }

    rt_err_t result = RT_EOK;
    int ai_run_complete_flag = 0;
    rt_ai_buffer_t *work_buff = rt_malloc(RT_AI_NETWORK_WORK_BUFFER_BYTES + RT_AI_NETWORK_IN_TOTAL_SIZE_BYTES + RT_AI_NETWORK_OUT_TOTAL_SIZE_BYTES);
    if(!work_buff)
    {
        rt_kprintf("rt_malloc err\n");
        return -1;
    }

    model = rt_ai_find(RT_AI_NETWORK_MODEL_NAME);
    if(model == RT_AI_NULL)
    {
        rt_kprintf("rt_ai not find\n");
        return -1;
    }

    result = rt_ai_init(model, work_buff);
    if(result != 0)
    {
        rt_kprintf("ai_init error\n");
        return -1;
    }
    else
    {
//        rt_kprintf("ai_init done\n");
    }

    rt_memcpy(model->input[0], &array_out_50X50_i[0][0], RT_AI_NETWORK_IN_1_SIZE_BYTES);
    result = rt_ai_run(model, ai_run_complete, &ai_run_complete_flag);
    if(result != 0)
    {
        rt_kprintf("ai model run error\n");
        return -1;
    }

    int if_Drown = 0;
    uint32_t out_uint32[2] = {0};
    if(ai_run_complete_flag)
    {
        int8_t *out = (int8_t *)rt_ai_output(model, 0);
        out_uint32[0] = out[0] + 128;
        out_uint32[1] = out[1] + 128;
//        rt_kprintf("Drown = %d, Swimming = %d\n", out_uint32[0], out_uint32[1]);
        if(out_uint32[0] >= 150)
        {
            if_Drown = 1;
        }
        else if(out_uint32[1] >= 150)
        {
            if_Drown = 2;
        }
//        rt_kprintf("%d\n", if_Drown);

        if(if_Drown == 1)
        {
            rt_kprintf("Drown\n");
            lcd_show_string(0, 240, 32, "Drown         ");
        }
        else if(if_Drown == 2)
        {
            rt_kprintf("Swimming\n");
            lcd_show_string(0, 240, 32, "Swimming     ");
        }
        else
        {
            rt_kprintf("Uncertain\n");
            lcd_show_string(0, 240, 32, "Uncertain ");
        }
    }
    rt_free(work_buff);
    return 0;
}
