/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon Jul 17 21:02:11 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"



#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 2
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "906603a75e2e7bf5827f1a3038fd3cd9"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Mon Jul 17 21:02:11 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_30_scratch0_array;   /* Array #0 */
AI_STATIC ai_array conv2d_29_scratch0_array;   /* Array #1 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #2 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #3 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #4 */
AI_STATIC ai_array conv2d_24_scratch0_array;   /* Array #5 */
AI_STATIC ai_array conv2d_23_scratch1_array;   /* Array #6 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #7 */
AI_STATIC ai_array conv2d_22_scratch1_array;   /* Array #8 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #9 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #10 */
AI_STATIC ai_array conv2d_20_scratch0_array;   /* Array #11 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #12 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #13 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #14 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #15 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #16 */
AI_STATIC ai_array conv2d_14_scratch0_array;   /* Array #17 */
AI_STATIC ai_array conv2d_12_scratch0_array;   /* Array #18 */
AI_STATIC ai_array conv2d_11_scratch1_array;   /* Array #19 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #20 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #21 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #22 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #23 */
AI_STATIC ai_array conv2d_6_scratch1_array;   /* Array #24 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #25 */
AI_STATIC ai_array conv2d_5_scratch1_array;   /* Array #26 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #27 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #28 */
AI_STATIC ai_array conv2d_2_scratch1_array;   /* Array #29 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #30 */
AI_STATIC ai_array conv2d_1_scratch1_array;   /* Array #31 */
AI_STATIC ai_array conv2d_1_scratch0_array;   /* Array #32 */
AI_STATIC ai_array conv2d_0_scratch0_array;   /* Array #33 */
AI_STATIC ai_array dense_32_bias_array;   /* Array #34 */
AI_STATIC ai_array dense_32_weights_array;   /* Array #35 */
AI_STATIC ai_array conv2d_30_bias_array;   /* Array #36 */
AI_STATIC ai_array conv2d_30_weights_array;   /* Array #37 */
AI_STATIC ai_array conv2d_29_bias_array;   /* Array #38 */
AI_STATIC ai_array conv2d_29_weights_array;   /* Array #39 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #40 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #41 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #42 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #43 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #44 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #45 */
AI_STATIC ai_array conv2d_24_bias_array;   /* Array #46 */
AI_STATIC ai_array conv2d_24_weights_array;   /* Array #47 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #48 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #49 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #50 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #51 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #52 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #53 */
AI_STATIC ai_array conv2d_20_bias_array;   /* Array #54 */
AI_STATIC ai_array conv2d_20_weights_array;   /* Array #55 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #56 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #57 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #58 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #59 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #60 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #61 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #62 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #63 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #64 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #65 */
AI_STATIC ai_array conv2d_14_bias_array;   /* Array #66 */
AI_STATIC ai_array conv2d_14_weights_array;   /* Array #67 */
AI_STATIC ai_array conv2d_12_bias_array;   /* Array #68 */
AI_STATIC ai_array conv2d_12_weights_array;   /* Array #69 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #70 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #71 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #72 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #73 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #74 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #75 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #76 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #77 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #78 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #79 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #80 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #81 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #82 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #83 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #84 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #85 */
AI_STATIC ai_array conv2d_1_bias_array;   /* Array #86 */
AI_STATIC ai_array conv2d_1_weights_array;   /* Array #87 */
AI_STATIC ai_array conv2d_0_bias_array;   /* Array #88 */
AI_STATIC ai_array conv2d_0_weights_array;   /* Array #89 */
AI_STATIC ai_array serving_default_x0_output_array;   /* Array #90 */
AI_STATIC ai_array conv2d_0_output_array;   /* Array #91 */
AI_STATIC ai_array conv2d_1_output_array;   /* Array #92 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #93 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #94 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #95 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #96 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #97 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #98 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #99 */
AI_STATIC ai_array conv2d_11_output_array;   /* Array #100 */
AI_STATIC ai_array conv2d_12_output_array;   /* Array #101 */
AI_STATIC ai_array conv2d_14_output_array;   /* Array #102 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #103 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #104 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #105 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #106 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #107 */
AI_STATIC ai_array conv2d_20_output_array;   /* Array #108 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #109 */
AI_STATIC ai_array conv2d_22_output_array;   /* Array #110 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #111 */
AI_STATIC ai_array conv2d_24_output_array;   /* Array #112 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #113 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #114 */
AI_STATIC ai_array conv2d_28_output_array;   /* Array #115 */
AI_STATIC ai_array conv2d_29_output_array;   /* Array #116 */
AI_STATIC ai_array conv2d_30_output_array;   /* Array #117 */
AI_STATIC ai_array dense_32_output_array;   /* Array #118 */
AI_STATIC ai_array dense_32_fmt_output_array;   /* Array #119 */
AI_STATIC ai_array nl_33_output_array;   /* Array #120 */
AI_STATIC ai_array nl_33_fmt_output_array;   /* Array #121 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_30_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_29_scratch0;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_24_scratch0;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_23_scratch1;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_22_scratch1;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_20_scratch0;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_14_scratch0;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_12_scratch0;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_11_scratch1;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_6_scratch1;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_5_scratch1;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_2_scratch1;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_1_scratch1;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_1_scratch0;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_0_scratch0;   /* Tensor #33 */
AI_STATIC ai_tensor dense_32_bias;   /* Tensor #34 */
AI_STATIC ai_tensor dense_32_weights;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_30_bias;   /* Tensor #36 */
AI_STATIC ai_tensor conv2d_30_weights;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_29_bias;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_29_weights;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #43 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_24_bias;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_24_weights;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_20_bias;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_20_weights;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #63 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #64 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_14_bias;   /* Tensor #66 */
AI_STATIC ai_tensor conv2d_14_weights;   /* Tensor #67 */
AI_STATIC ai_tensor conv2d_12_bias;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_12_weights;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #74 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #75 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_1_bias;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_1_weights;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_0_bias;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_0_weights;   /* Tensor #89 */
AI_STATIC ai_tensor serving_default_x0_output;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_0_output;   /* Tensor #91 */
AI_STATIC ai_tensor conv2d_1_output;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #95 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #99 */
AI_STATIC ai_tensor conv2d_11_output;   /* Tensor #100 */
AI_STATIC ai_tensor conv2d_12_output;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_14_output;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_20_output;   /* Tensor #108 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #109 */
AI_STATIC ai_tensor conv2d_22_output;   /* Tensor #110 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #111 */
AI_STATIC ai_tensor conv2d_24_output;   /* Tensor #112 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #113 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #114 */
AI_STATIC ai_tensor conv2d_28_output;   /* Tensor #115 */
AI_STATIC ai_tensor conv2d_29_output;   /* Tensor #116 */
AI_STATIC ai_tensor conv2d_30_output;   /* Tensor #117 */
AI_STATIC ai_tensor dense_32_output;   /* Tensor #118 */
AI_STATIC ai_tensor dense_32_fmt_output;   /* Tensor #119 */
AI_STATIC ai_tensor nl_33_output;   /* Tensor #120 */
AI_STATIC ai_tensor nl_33_fmt_output;   /* Tensor #121 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_1_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv2d_11_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_12_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_14_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv2d_20_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_22_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv2d_24_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain conv2d_28_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain conv2d_29_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_30_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain dense_32_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain dense_32_fmt_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain nl_33_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain nl_33_fmt_chain;   /* Chain #30 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv2d_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_1_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv2d_11_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_12_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_14_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv2d_20_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_22_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv2d_24_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #23 */
AI_STATIC ai_layer_conv2d conv2d_28_layer; /* Layer #24 */
AI_STATIC ai_layer_conv2d conv2d_29_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d conv2d_30_layer; /* Layer #26 */
AI_STATIC ai_layer_dense dense_32_layer; /* Layer #27 */
AI_STATIC ai_layer_nl dense_32_fmt_layer; /* Layer #28 */
AI_STATIC ai_layer_nl nl_33_layer; /* Layer #29 */
AI_STATIC ai_layer_nl nl_33_fmt_layer; /* Layer #30 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9473, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1185, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1185, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 593, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10000, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5000, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 297, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 292, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  dense_32_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 2, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  dense_32_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_x0_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2500, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5000, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5000, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10000, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  dense_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  dense_32_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  nl_33_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  nl_33_fmt_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_32_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.3963871323503554e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_32_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002545636147260666f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.055452442727983e-05f, 9.423133451491594e-05f, 9.212049189954996e-05f, 8.068191527854651e-05f, 8.898241503629833e-05f, 8.374729804927483e-05f, 7.880907651269808e-05f, 9.390147897647694e-05f, 9.753415361046791e-05f, 7.331179949687794e-05f, 0.00011203109170310199f, 0.00011463173723313957f, 7.198886305559427e-05f, 8.749154949327931e-05f, 8.145201718434691e-05f, 7.878980250097811e-05f, 9.326064900960773e-05f, 9.868301276583225e-05f, 8.549368794774637e-05f, 0.00010450931586092338f, 9.673453314462677e-05f, 9.585816587787122e-05f, 7.691111386520788e-05f, 9.816382953431457e-05f, 8.990686183096841e-05f, 9.99916810542345e-05f, 8.376980986213312e-05f, 0.00010733963426901028f, 0.00014445265696849674f, 8.175987022696063e-05f, 8.970241469796747e-05f, 8.234851702582091e-05f, 0.00010899363405769691f, 7.331688539125025e-05f, 7.880417251726612e-05f, 7.892593566793948e-05f, 9.088388469535857e-05f, 0.00010130066220881417f, 9.56420335569419e-05f, 9.320474055130035e-05f, 8.513598004356027e-05f, 7.352040120167658e-05f, 9.416006651008502e-05f, 8.24680901132524e-05f, 8.192118548322469e-05f, 7.667917088838294e-05f, 7.231245399452746e-05f, 8.868057193467394e-05f, 7.374851702479646e-05f, 8.915470243664458e-05f, 7.687875040573999e-05f, 8.67617636686191e-05f, 9.048893116414547e-05f, 9.348400635644794e-05f, 7.704809831921011e-05f, 6.618601764785126e-05f, 0.00010084117820952088f, 8.687150693731382e-05f, 8.359597268281505e-05f, 9.748271986609325e-05f, 8.726376836420968e-05f, 9.904898615786806e-05f, 7.248374458868057e-05f, 7.94019506429322e-05f, 8.098245598375797e-05f, 8.084633009275422e-05f, 9.317544754594564e-05f, 9.02566680451855e-05f, 0.00015520084707532078f, 8.693460404174402e-05f, 0.00011517528037074953f, 8.307983807753772e-05f, 9.397228859597817e-05f, 7.692914368817583e-05f, 6.51075315545313e-05f, 9.476229752181098e-05f, 8.10184283182025e-05f, 7.00321834301576e-05f, 8.976690878625959e-05f, 8.176239498425275e-05f, 9.207030234392732e-05f, 7.559980440419167e-05f, 9.293361654272303e-05f, 8.836235792841762e-05f, 8.159586286637932e-05f, 7.162646215874702e-05f, 9.19806188903749e-05f, 0.00012096438877051696f, 8.742243517190218e-05f, 7.704302697675303e-05f, 7.918784831417724e-05f, 0.0001037182446452789f, 8.065054134931415e-05f, 7.973191532073542e-05f, 8.002301910892129e-05f, 0.000103658479929436f, 8.515793160768226e-05f, 9.710201265988871e-05f, 8.437546784989536e-05f, 9.01398088899441e-05f, 0.00011878000077558681f, 0.0001097517233574763f, 8.08585318736732e-05f, 0.00013888967805542052f, 0.00010684099106583744f, 9.025015606312081e-05f, 7.79414112912491e-05f, 0.00011909529712283984f, 8.809618157101795e-05f, 9.59068929660134e-05f, 8.433495531789958e-05f, 9.95288573903963e-05f, 0.00010814036795636639f, 8.381237421417609e-05f, 8.272450941149145e-05f, 8.240865281550214e-05f, 8.248176891356707e-05f, 8.948367758421227e-05f, 9.119084279518574e-05f, 9.709124424261972e-05f, 7.899435149738565e-05f, 0.00011352963338140398f, 8.529181650374085e-05f, 7.918952906038612e-05f, 9.535162098472938e-05f, 7.09254018147476e-05f, 8.438619261141866e-05f, 7.862679922254756e-05f, 7.949150312924758e-05f, 7.33031120034866e-05f, 8.027171134017408e-05f, 7.943567470647395e-05f, 9.14766569621861e-05f, 9.922555909724906e-05f, 7.748923235340044e-05f, 0.00010437577293487266f, 9.610744018573314e-05f, 7.705538882873952e-05f, 0.00010870093683479354f, 8.572888327762485e-05f, 8.525113662471995e-05f, 9.433968807570636e-05f, 8.210328815039247e-05f, 0.00011147485201945528f, 7.008782995399088e-05f, 9.700844384497032e-05f, 7.98204928287305e-05f, 8.909527969080955e-05f, 7.98385008238256e-05f, 8.200980664696544e-05f, 8.142500882968307e-05f, 8.541315037291497e-05f, 9.258239879272878e-05f, 8.776410686550662e-05f, 0.00010750304500106722f, 8.127392356982455e-05f, 0.00010161261889152229f, 0.00010498413757886738f, 9.692350431578234e-05f, 0.00010244655277347192f, 8.663076005177572e-05f, 6.908381328685209e-05f, 8.028823503991589e-05f, 0.00010544931865297258f, 8.784666715655476e-05f, 0.00010833619307959452f, 0.00013002842024434358f, 8.83829707163386e-05f, 9.08029978745617e-05f, 0.0001202522253151983f, 9.57782831392251e-05f, 8.923175482777879e-05f, 8.061836706474423e-05f, 8.551840437576175e-05f, 9.134232823271304e-05f, 0.00013532978482544422f, 9.177390165859833e-05f, 8.361259824596345e-05f, 8.650655945530161e-05f, 8.548091864213347e-05f, 8.099758269963786e-05f, 9.662157390266657e-05f, 8.710363181307912e-05f, 8.286200318252668e-05f, 0.00012074344704160467f, 7.808332884451374e-05f, 0.00010286481847288087f, 8.999449346447363e-05f, 8.6939413449727e-05f, 6.079558443161659e-05f, 7.677012035856023e-05f, 7.887607353040949e-05f, 0.00010462897625984624f, 0.0002487254678271711f, 8.112183422781527e-05f, 8.832052117213607e-05f, 7.732928497716784e-05f, 6.998515891609713e-05f, 8.11753052403219e-05f, 8.862347021931782e-05f, 0.00010915140592260286f, 9.183716611005366e-05f, 0.0001005866433843039f, 0.00012261958909220994f, 7.412924605887383e-05f, 9.877297270577401e-05f, 7.87500393926166e-05f, 8.301449270220473e-05f, 8.599185821367428e-05f, 0.00010411765106255189f, 0.00011324085789965466f, 8.720679761609063e-05f, 9.46641230257228e-05f, 8.435607014689595e-05f, 0.00010017118620453402f, 9.368773316964507e-05f, 8.995411917567253e-05f, 0.00010013559949584305f, 0.00011068346066167578f, 9.194446465699002e-05f, 8.273940329672769e-05f, 8.44993264763616e-05f, 6.939755257917568e-05f, 0.00013849089737050235f, 7.895571616245434e-05f, 9.53367562033236e-05f, 9.849952766671777e-05f, 7.28122322470881e-05f, 7.498382910853252e-05f, 9.384151780977845e-05f, 9.831524221226573e-05f, 9.357146336697042e-05f, 0.00010174086492042989f, 8.307868847623467e-05f, 0.00010626377479638904f, 6.995023431954905e-05f, 0.00013046264939475805f, 7.847711094655097e-05f, 8.743986109038815e-05f, 0.00010586350254015997f, 0.00011022522812709212f, 9.62934282142669e-05f, 8.8048393081408e-05f, 7.751830708002672e-05f, 9.182565554510802e-05f, 0.00010651088814483956f, 9.40385289140977e-05f, 0.00010570226731942967f, 7.836474105715752e-05f, 0.00010886672680499032f, 7.420102338073775e-05f, 0.00010072193981613964f, 6.132311682449654e-05f, 8.77181810210459e-05f, 8.739627810427919e-05f, 7.33175766072236e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004463716875761747f, 0.0059616584330797195f, 0.0058281137607991695f, 0.005104438401758671f, 0.005629579536616802f, 0.0052983732894063f, 0.0049859508872032166f, 0.005940789822489023f, 0.006170615553855896f, 0.004638159181922674f, 0.007087781559675932f, 0.00725231459364295f, 0.004554461687803268f, 0.00553525798022747f, 0.005153159610927105f, 0.004984731320291758f, 0.005900247022509575f, 0.006243299227207899f, 0.005408860743045807f, 0.006611907389014959f, 0.0061200265772640705f, 0.006064582150429487f, 0.004865874070674181f, 0.006210452411323786f, 0.00568806566298008f, 0.006326093804091215f, 0.005299797747284174f, 0.006790970917791128f, 0.009138970635831356f, 0.0051726363599300385f, 0.005675130989402533f, 0.005209878087043762f, 0.006895613390952349f, 0.004638480953872204f, 0.00498564075678587f, 0.0049933441914618015f, 0.005749878007918596f, 0.006408907938748598f, 0.0060509080067276955f, 0.005896709859371185f, 0.005386230070143938f, 0.004651356488466263f, 0.005957149900496006f, 0.005217442754656076f, 0.005182842258363962f, 0.004851199686527252f, 0.004574934486299753f, 0.005610482767224312f, 0.004665788728743792f, 0.0056404792703688145f, 0.004863826557993889f, 0.005489087197929621f, 0.00572489108890295f, 0.0059143779799342155f, 0.004874540492892265f, 0.004187338054180145f, 0.006379838101565838f, 0.005496030207723379f, 0.00528879975900054f, 0.0061673615127801895f, 0.005520847160369158f, 0.006266453303396702f, 0.004585771355777979f, 0.005023459903895855f, 0.00512345228344202f, 0.005114840343594551f, 0.0058948565274477005f, 0.005710196681320667f, 0.00981896836310625f, 0.005500022321939468f, 0.007286702282726765f, 0.005256145726889372f, 0.005945269949734211f, 0.004867014475166798f, 0.004119106102734804f, 0.0059952507726848125f, 0.005125728435814381f, 0.004430670291185379f, 0.005679211113601923f, 0.005172796081751585f, 0.005824938416481018f, 0.0047829123213887215f, 0.005879556760191917f, 0.005590350832790136f, 0.005162260495126247f, 0.004531534388661385f, 0.005819264333695173f, 0.007652957458049059f, 0.005530885420739651f, 0.00487421965226531f, 0.00500991428270936f, 0.0065618595108389854f, 0.005102453287690878f, 0.005044335499405861f, 0.005062752403318882f, 0.006558078341186047f, 0.00538761867210269f, 0.006143275648355484f, 0.005338115151971579f, 0.005702803377062082f, 0.007514759432524443f, 0.006943574640899897f, 0.00511561194434762f, 0.008787021972239017f, 0.006759423762559891f, 0.0057097845710814f, 0.004931056872010231f, 0.007534706965088844f, 0.005573510657995939f, 0.0060676648281514645f, 0.005335552152246237f, 0.006296812556684017f, 0.006841630209237337f, 0.005302490666508675f, 0.0052336654625833035f, 0.0052136825397610664f, 0.0052183084189891815f, 0.005661292467266321f, 0.0057692984119057655f, 0.006142594385892153f, 0.004997672513127327f, 0.007182588800787926f, 0.0053960890509188175f, 0.005010020919144154f, 0.006032534874975681f, 0.00448718061670661f, 0.005338794086128473f, 0.00497441878542304f, 0.005029125604778528f, 0.004637609235942364f, 0.005078486166894436f, 0.005025593563914299f, 0.005787380505353212f, 0.006277624052017927f, 0.004902449436485767f, 0.006603458896279335f, 0.0060803527012467384f, 0.004875001963227987f, 0.006877095438539982f, 0.005423740949481726f, 0.005393515806645155f, 0.005968513898551464f, 0.005194363184273243f, 0.0070525906048715115f, 0.0044341906905174255f, 0.006137355696409941f, 0.005049939267337322f, 0.005636719986796379f, 0.005051078740507364f, 0.005188448820263147f, 0.005151451099663973f, 0.005403765477240086f, 0.005857336800545454f, 0.005552501883357763f, 0.006801309529691935f, 0.005141892470419407f, 0.006428644526749849f, 0.006641947664320469f, 0.006131981965154409f, 0.0064814044162631035f, 0.00548079889267683f, 0.004370670299977064f, 0.005079531576484442f, 0.006671377923339605f, 0.005557724740356207f, 0.006854019593447447f, 0.008226403966546059f, 0.005591654684394598f, 0.0057447608560323715f, 0.007607901468873024f, 0.006059528328478336f, 0.005645354278385639f, 0.005100417882204056f, 0.005410424433648586f, 0.005778882186859846f, 0.008561801165342331f, 0.005806186236441135f, 0.005289851687848568f, 0.0054729413241147995f, 0.005408052820712328f, 0.005124409217387438f, 0.006112880073487759f, 0.005510715767741203f, 0.005242364015430212f, 0.007638979237526655f, 0.004940035752952099f, 0.00650786655023694f, 0.005693609826266766f, 0.00550032639876008f, 0.0038463056553155184f, 0.004856953863054514f, 0.004990189336240292f, 0.0066194781102240086f, 0.015735914930701256f, 0.005132270511239767f, 0.005587704014033079f, 0.004892330151051283f, 0.00442769518122077f, 0.0051356530748307705f, 0.005606870166957378f, 0.00690559484064579f, 0.005810188595205545f, 0.006363735068589449f, 0.007757675368338823f, 0.004689875990152359f, 0.006248991005122662f, 0.004982215818017721f, 0.005252011585980654f, 0.005440378095954657f, 0.006587128154933453f, 0.007164319045841694f, 0.005517242942005396f, 0.005989039316773415f, 0.005336888134479523f, 0.006337450351566076f, 0.0059272670187056065f, 0.005691055208444595f, 0.006335198879241943f, 0.007002522237598896f, 0.005816977005451918f, 0.005234607961028814f, 0.005345951300114393f, 0.004390519578009844f, 0.008761793375015259f, 0.004995228257030249f, 0.00603159423917532f, 0.0062316907569766045f, 0.004606553353369236f, 0.004743942059576511f, 0.005936996545642614f, 0.006220031995326281f, 0.005919910967350006f, 0.006436758209019899f, 0.005256073083728552f, 0.006722905207425356f, 0.004425485618412495f, 0.008253876119852066f, 0.004964948631823063f, 0.005531987641006708f, 0.0066975816152989864f, 0.006973531562834978f, 0.006092119496315718f, 0.005570487584918737f, 0.004904288798570633f, 0.005809460300952196f, 0.006738539319485426f, 0.005949460435658693f, 0.006687380839139223f, 0.004957839380949736f, 0.006887584459036589f, 0.004694417119026184f, 0.0063722943887114525f, 0.0038796805310994387f, 0.005549596156924963f, 0.005529230460524559f, 0.004638524726033211f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.877072443487123e-05f, 0.00010592641774564981f, 7.148729491746053e-05f, 5.557298572966829e-05f, 0.00022389499645214528f, 7.054140587570146e-05f, 6.657957419520244e-05f, 3.9889295294415206e-05f, 0.00010887442476814613f, 7.57002635509707e-05f, 4.961400554748252e-05f, 8.860652451403439e-05f, 7.858836761442944e-05f, 6.56050760881044e-05f, 7.152649050112814e-05f, 0.0001248048065463081f, 4.428730608196929e-05f, 6.476994894910604e-05f, 0.00014979411207605153f, 5.231410250416957e-05f, 0.00016790319932624698f, 6.338868843158707e-05f, 6.486738129751757e-05f, 8.317054744111374e-05f, 0.00011955533409491181f, 0.00015206249372567981f, 8.463051199214533e-05f, 0.00011895627540070564f, 6.691017188131809e-05f, 7.059048948576674e-05f, 7.171961624408141e-05f, 0.0001348453079117462f, 0.00010584059782559052f, 6.636692705797032e-05f, 5.640294693876058e-05f, 4.915077443001792e-05f, 9.995420259656385e-05f, 6.747035513399169e-05f, 4.936517507303506e-05f, 0.00010573630424914882f, 8.176964911399409e-05f, 6.72218156978488e-05f, 5.253754716250114e-05f, 4.191525295027532e-05f, 4.723099118564278e-05f, 5.559763667406514e-05f, 0.00010608270531520247f, 8.955644443631172e-05f, 7.083358650561422e-05f, 0.00011917681695194915f, 4.8748450353741646e-05f, 0.00010881417983910069f, 0.0001034470260492526f, 6.234958709683269e-05f, 3.910002124030143e-05f, 0.00010514041059650481f, 8.682253974257037e-05f, 9.415033127879724e-05f, 4.860722765442915e-05f, 5.817260898766108e-05f, 7.547556015197188e-05f, 6.724902777932584e-05f, 0.00020803352526854724f, 8.899748354451731e-05f, 0.0001306051854044199f, 6.615821621380746e-05f, 6.700273661408573e-05f, 6.563338683918118e-05f, 6.48584173177369e-05f, 6.658190977759659e-05f, 7.394633576041088e-05f, 5.1355254981899634e-05f, 9.774824866326526e-05f, 8.151129441102967e-05f, 8.407016139244661e-05f, 9.229824354406446e-05f, 4.701677244156599e-05f, 5.317308023222722e-05f, 0.000152147127664648f, 8.292897837236524e-05f, 6.237890920601785e-05f, 7.69534453866072e-05f, 7.032907888060436e-05f, 5.848865839652717e-05f, 0.00011855375487357378f, 5.830945883644745e-05f, 8.219968003686517e-05f, 0.00010310821380699053f, 0.0001892585278255865f, 6.367691821651533e-05f, 5.627697828458622e-05f, 7.581344107165933e-05f, 0.00012280413648113608f, 6.585035589523613e-05f, 5.845687337568961e-05f, 7.654252840438858e-05f, 6.188631959958002e-05f, 7.525845285272226e-05f, 6.38826604699716e-05f, 9.805525041883811e-05f, 0.00010734084935393184f, 8.239207818405703e-05f, 5.6797522120177746e-05f, 0.00016858837625477463f, 7.019073382252827e-05f, 0.00012573617277666926f, 6.407574255717918e-05f, 5.475674333865754e-05f, 7.167998410295695e-05f, 9.723410767037421e-05f, 0.00015694698959123343f, 0.00013917878095526248f, 0.00010514336463529617f, 0.00013908641994930804f, 5.764637535321526e-05f, 7.116154301911592e-05f, 7.330412336159497e-05f, 8.010044984985143e-05f, 4.7311790694948286e-05f, 8.84280088939704e-05f, 9.282376413466409e-05f, 7.96332533354871e-05f, 8.171013905666769e-05f, 7.147691212594509e-05f, 7.547800487373024e-05f, 0.00014880225353408605f, 7.472199649782851e-05f, 0.00011135115346405655f, 7.00823511579074e-05f, 0.00012108383816666901f, 6.999132892815396e-05f, 5.010649692849256e-05f, 5.334550951374695e-05f, 8.0378886195831e-05f, 5.705393050448038e-05f, 8.335126767633483e-05f, 7.825117063475773e-05f, 5.696653897757642e-05f, 5.639784285449423e-05f, 9.712195605970919e-05f, 4.7522542445221916e-05f, 5.483121276483871e-05f, 7.220933912321925e-05f, 7.900582568254322e-05f, 0.00014109720359556377f, 6.164157093735412e-05f, 7.526197441620752e-05f, 5.987016993458383e-05f, 0.00012988924572709948f, 0.0001429680414730683f, 7.173807534854859e-05f, 8.736833115108311e-05f, 0.00012355791113805026f, 0.0001168672097264789f, 6.0050315369153395e-05f, 7.810130045982078e-05f, 8.523689757566899e-05f, 7.958845526445657e-05f, 8.046688162721694e-05f, 0.00010659540566848591f, 9.763841808307916e-05f, 0.00011315058509353548f, 6.636705074924976e-05f, 0.00016789627261459827f, 6.17051191511564e-05f, 6.896335253259167e-05f, 9.925624181050807e-05f, 7.605370774399489e-05f, 0.00011914676724700257f, 7.35432913643308e-05f, 9.004769526654854e-05f, 6.94058180670254e-05f, 6.383381696650758e-05f, 7.695205567870289e-05f, 9.061783202923834e-05f, 7.959781214594841e-05f, 5.955927190370858e-05f, 5.384299220168032e-05f, 6.351201591314748e-05f, 6.299057713476941e-05f, 6.973278505029157e-05f, 7.635277870576829e-05f, 7.473739242414013e-05f, 9.978074376704171e-05f, 8.456868090434e-05f, 7.652935164514929e-05f, 7.117579662008211e-05f, 8.435689960606396e-05f, 6.049155126675032e-05f, 0.00012056151899741963f, 6.782136915717274e-05f, 8.132030052365735e-05f, 0.00012002352741546929f, 0.00013682937424164265f, 9.156675514532253e-05f, 4.5664168283110484e-05f, 6.581335765076801e-05f, 7.538493082392961e-05f, 7.392466795863584e-05f, 4.348521906649694e-05f, 6.379945989465341e-05f, 4.5188375224824995e-05f, 6.612527795368806e-05f, 9.562953346176073e-05f, 5.901881741010584e-05f, 0.0001315544795943424f, 5.8741599787026644e-05f, 5.5146832892205566e-05f, 0.00013838670565746725f, 0.00010952400043606758f, 0.00016130229050759226f, 8.482645353069529e-05f, 7.559049845440313e-05f, 7.038659532554448e-05f, 7.206919690361246e-05f, 8.117756806313992e-05f, 7.578518125228584e-05f, 5.6754954130155966e-05f, 9.84922080533579e-05f, 6.714022310916334e-05f, 0.00010187684529228136f, 7.235819794004783e-05f, 7.696499233134091e-05f, 6.951161776669323e-05f, 6.786133599234745e-05f, 0.0001730158255668357f, 5.507930836756714e-05f, 0.00012790558685082942f, 7.655138324480504e-05f, 7.69697580835782e-05f, 9.614252485334873e-05f, 0.00013609569577965885f, 6.139266770333052e-05f, 0.00012426306784618646f, 6.71426605549641e-05f, 6.20677528786473e-05f, 6.522142939502373e-05f, 8.223424811149016e-05f, 6.858225242467597e-05f, 0.00010947581176878884f, 5.304804290062748e-05f, 6.89115549903363e-05f, 4.6272343752207235e-05f, 9.036248957272619e-05f, 5.479206083691679e-05f, 7.053815352264792e-05f, 0.0001566919090691954f, 6.0448277508839965e-05f, 4.918852573609911e-05f, 0.0001101584784919396f, 0.00012372528726700693f, 5.9892525314353406e-05f, 7.817372534191236e-05f, 9.022761514643207e-05f, 6.628632399952039e-05f, 0.00010206251317868009f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006828650366514921f, 0.007323368918150663f, 0.004942372906953096f, 0.0038421149365603924f, 0.01547928899526596f, 0.004876977298408747f, 0.004603070672601461f, 0.002757801441475749f, 0.007527183275669813f, 0.005233642179518938f, 0.0034301327541470528f, 0.006125934422016144f, 0.005433314945548773f, 0.004535697400569916f, 0.00494508258998394f, 0.00862855277955532f, 0.00306186405941844f, 0.004477959591895342f, 0.010356222279369831f, 0.0036168075166642666f, 0.011608218774199486f, 0.0043824645690619946f, 0.004484695848077536f, 0.005750110372900963f, 0.008265622891485691f, 0.010513050481677055f, 0.005851047113537788f, 0.008224206045269966f, 0.0046259271912276745f, 0.0048803710378706455f, 0.004958434496074915f, 0.009322715923190117f, 0.007317435462027788f, 0.0045883688144385815f, 0.0038994955830276012f, 0.0033981066662818193f, 0.006910471711307764f, 0.004664656240493059f, 0.0034129293635487556f, 0.007310225162655115f, 0.005653257481753826f, 0.004647472873330116f, 0.003632255829870701f, 0.002897868864238262f, 0.0032653796952217817f, 0.0038438192568719387f, 0.007334174122661352f, 0.0061916084960103035f, 0.0048971776850521564f, 0.00823945365846157f, 0.003370291320607066f, 0.007523018401116133f, 0.0071519529446959496f, 0.004310624673962593f, 0.002703233854845166f, 0.007269027177244425f, 0.006002596113830805f, 0.006509213242679834f, 0.003360527800396085f, 0.004021843429654837f, 0.005218106787651777f, 0.0046493541449308395f, 0.014382684603333473f, 0.0061529637314379215f, 0.00902956910431385f, 0.0045739393681287766f, 0.004632326774299145f, 0.00453765457496047f, 0.004484076052904129f, 0.004603232257068157f, 0.005112381651997566f, 0.003550516441464424f, 0.006757959723472595f, 0.005635395646095276f, 0.005812306422740221f, 0.0063811661675572395f, 0.003250569337978959f, 0.003676194231957197f, 0.01051890105009079f, 0.005733409430831671f, 0.004312652163207531f, 0.005320282652974129f, 0.0048622977919876575f, 0.004043694119900465f, 0.008196377195417881f, 0.004031304735690355f, 0.005682988092303276f, 0.007128528319299221f, 0.013084649108350277f, 0.004402391612529755f, 0.0038907865528017282f, 0.00524146668612957f, 0.008490233682096004f, 0.004552654922008514f, 0.00404149666428566f, 0.005291873123496771f, 0.0042785960249602795f, 0.005203097127377987f, 0.004416615702211857f, 0.006779185030609369f, 0.007421157788485289f, 0.005696290172636509f, 0.003926774952560663f, 0.011655589565634727f, 0.004852733109146357f, 0.00869294349104166f, 0.004429964814335108f, 0.0037856828421354294f, 0.004955694545060396f, 0.006722413934767246f, 0.010850746184587479f, 0.009622316807508469f, 0.007269231602549553f, 0.009615931659936905f, 0.00398546177893877f, 0.004919851198792458f, 0.005067981779575348f, 0.005537854973226786f, 0.003270966000854969f, 0.0061135925352573395f, 0.006417498923838139f, 0.005505554843693972f, 0.005649142898619175f, 0.004941654857248068f, 0.00521827582269907f, 0.010287648998200893f, 0.0051660081371665f, 0.007698415778577328f, 0.004845240153372288f, 0.00837129820138216f, 0.004838947206735611f, 0.003464181674644351f, 0.003688115393742919f, 0.0055571049451828f, 0.0039445022121071815f, 0.005762604996562004f, 0.0054100025445222855f, 0.003938460256904364f, 0.003899142611771822f, 0.006714660208672285f, 0.003285536542534828f, 0.0037908314261585474f, 0.004992292262613773f, 0.0054621766321361065f, 0.009754950180649757f, 0.004261674825102091f, 0.0052033402025699615f, 0.00413920683786273f, 0.008980072103440762f, 0.00988429319113493f, 0.0049597108736634254f, 0.006040330044925213f, 0.008542346768081188f, 0.008079775609076023f, 0.004151661414653063f, 0.005399641115218401f, 0.005892970599234104f, 0.005502457730472088f, 0.005563188809901476f, 0.007369620259851217f, 0.006750366650521755f, 0.007822821848094463f, 0.00458837766200304f, 0.011607740074396133f, 0.004266068339347839f, 0.004767876584082842f, 0.006862217094749212f, 0.005258077755570412f, 0.008237375877797604f, 0.005084516946226358f, 0.0062255715020000935f, 0.004798466805368662f, 0.004413239192217588f, 0.005320186261087656f, 0.006264988798648119f, 0.005503104534000158f, 0.004117712378501892f, 0.003722509602084756f, 0.004390990827232599f, 0.004354940261691809f, 0.004821072332561016f, 0.005278754513710737f, 0.005167072638869286f, 0.006898479536175728f, 0.005846772342920303f, 0.005290962290018797f, 0.004920837003737688f, 0.005832130555063486f, 0.004182166885584593f, 0.00833518709987402f, 0.004688923712819815f, 0.005622191354632378f, 0.008297991938889027f, 0.009459887631237507f, 0.006330593954771757f, 0.003157055238261819f, 0.004550097044557333f, 0.005211841315031052f, 0.005110883619636297f, 0.003006410552188754f, 0.004410863853991032f, 0.0031241606920957565f, 0.004571662284433842f, 0.0066114794462919235f, 0.004080347251147032f, 0.009095200337469578f, 0.00406118156388402f, 0.003812652314081788f, 0.009567555971443653f, 0.007572092581540346f, 0.011151856742799282f, 0.005864593666046858f, 0.005226053297519684f, 0.004866274539381266f, 0.004982603248208761f, 0.005612323060631752f, 0.005239513237029314f, 0.003923831973224878f, 0.006809394806623459f, 0.00464183185249567f, 0.00704339612275362f, 0.005002583842724562f, 0.005321080796420574f, 0.004805781412869692f, 0.004691686946898699f, 0.011961687356233597f, 0.003807984059676528f, 0.008842929266393185f, 0.0052924854680895805f, 0.005321410484611988f, 0.00664694607257843f, 0.00940916407853365f, 0.004244466777890921f, 0.008591098710894585f, 0.004642000421881676f, 0.004291139543056488f, 0.004509173333644867f, 0.005685378331691027f, 0.004741528537124395f, 0.007568761240690947f, 0.0036675496958196163f, 0.004764295183122158f, 0.003199102357029915f, 0.006247335579246283f, 0.003788124769926071f, 0.004876752384006977f, 0.010833111591637135f, 0.004179175011813641f, 0.0034007164649665356f, 0.0076159583404660225f, 0.008553918451070786f, 0.004140752367675304f, 0.005404648371040821f, 0.006238010711967945f, 0.00458279624581337f, 0.007056232541799545f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.5049622965743765e-05f, 1.8950267985928804e-05f, 4.476212052395567e-05f, 3.284237391198985e-05f, 2.077859426208306e-05f, 3.0637096642749384e-05f, 3.701763125718571e-05f, 6.406177999451756e-05f, 2.7468691769172437e-05f, 3.416177423787303e-05f, 5.48735297343228e-05f, 1.9521205103956163e-05f, 2.947296525235288e-05f, 2.72354154731147e-05f, 4.5963384764036164e-05f, 2.194357330154162e-05f, 4.0225801058113575e-05f, 4.949648428009823e-05f, 1.4275233297667e-05f, 5.2138493629172444e-05f, 1.6999645595205948e-05f, 3.870446380460635e-05f, 4.5887689338997006e-05f, 5.200331361265853e-05f, 1.9783656171057373e-05f, 2.7469228371046484e-05f, 2.0695271814474836e-05f, 4.218300455249846e-05f, 4.779428127221763e-05f, 4.593177800416015e-05f, 2.172883068851661e-05f, 1.4932166777725797e-05f, 2.649919770192355e-05f, 3.6298584745964035e-05f, 4.5342498196987435e-05f, 2.7212687200517394e-05f, 2.2968724806560203e-05f, 3.741269756574184e-05f, 4.0117061871569604e-05f, 2.1670557543984614e-05f, 2.7888485419680364e-05f, 3.956414366257377e-05f, 4.682211147155613e-05f, 3.008823659911286e-05f, 3.535077121341601e-05f, 3.108446981059387e-05f, 1.8213362636743113e-05f, 2.5019018721650355e-05f, 2.1043913875473663e-05f, 3.511545219225809e-05f, 3.379786721779965e-05f, 2.519272493373137e-05f, 1.7743637727107853e-05f, 3.157653191010468e-05f, 3.494074917398393e-05f, 2.1025954993092455e-05f, 2.7636478989734314e-05f, 2.1467300030053593e-05f, 2.9882705348427407e-05f, 3.98540505557321e-05f, 1.975146915356163e-05f, 4.6691897296113893e-05f, 2.2837637516204268e-05f, 3.443167588557117e-05f, 1.7377486074110493e-05f, 2.7687439796864055e-05f, 2.329514973098412e-05f, 3.489521623123437e-05f, 3.700730303535238e-05f, 4.098760837223381e-05f, 3.136316081508994e-05f, 2.3127387976273894e-05f, 1.7372107322444208e-05f, 1.8470742361387238e-05f, 2.1854270016774535e-05f, 3.2294989068759605e-05f, 3.025490150321275e-05f, 3.0935960239730775e-05f, 2.641470382513944e-05f, 2.643179686856456e-05f, 4.8676785809220746e-05f, 3.544949140632525e-05f, 3.886930426233448e-05f, 2.1597144950646907e-05f, 2.921783016063273e-05f, 4.0322807763004676e-05f, 3.6672128771897405e-05f, 3.3937423722818494e-05f, 3.0150860766298138e-05f, 6.219760689418763e-05f, 4.695083771366626e-05f, 2.9513981644413434e-05f, 2.0053088519489393e-05f, 2.721788769122213e-05f, 4.166126745985821e-05f, 2.4045142708928324e-05f, 4.110581357963383e-05f, 2.8572712835739367e-05f, 5.462209810502827e-05f, 2.535410203563515e-05f, 3.390571509953588e-05f, 2.3617965780431405e-05f, 4.0696577343624085e-05f, 2.0698083972092718e-05f, 4.3147192627657205e-05f, 2.5437639123992994e-05f, 5.268076347419992e-05f, 3.954803469241597e-05f, 3.8422414945671335e-05f, 3.663286770461127e-05f, 3.551000190782361e-05f, 1.8372822523815557e-05f, 2.935377233370673e-05f, 3.177206599502824e-05f, 3.283478145021945e-05f, 2.3525501092080958e-05f, 2.2372247258317657e-05f, 5.096871973364614e-05f, 4.7971090680221096e-05f, 5.2234285249141976e-05f, 3.256958007114008e-05f, 2.7510990548762493e-05f, 3.813392686424777e-05f, 4.050370989716612e-05f, 2.8106825993745588e-05f, 1.4374401871464215e-05f, 2.6639159841579385e-05f, 1.7860471416497603e-05f, 3.92670881410595e-05f, 3.499711965559982e-05f, 4.597671431838535e-05f, 4.942884697811678e-05f, 3.216802724637091e-05f, 2.505983502487652e-05f, 3.269796070526354e-05f, 3.802333594649099e-05f, 3.694078986882232e-05f, 4.0813662053551525e-05f, 3.762598862522282e-05f, 3.78033728338778e-05f, 3.31298251694534e-05f, 3.230113725294359e-05f, 2.4674982341821305e-05f, 4.0587936382507905e-05f, 1.559247903060168e-05f, 2.6249133952660486e-05f, 2.5693720090202987e-05f, 4.2846251744776964e-05f, 1.8322825781069696e-05f, 1.621132469153963e-05f, 3.757181184482761e-05f, 3.234374162275344e-05f, 1.886970130726695e-05f, 1.5175740372797009e-05f, 3.264251790824346e-05f, 3.627914338721894e-05f, 2.435496026009787e-05f, 4.7681696742074564e-05f, 1.9204147974960506e-05f, 3.907792779500596e-05f, 2.372321796428878e-05f, 2.161065822292585e-05f, 3.438381463638507e-05f, 1.3148333891876973e-05f, 4.1549279558239505e-05f, 3.847404150292277e-05f, 2.3700740712229162e-05f, 3.916734567610547e-05f, 3.673154424177483e-05f, 3.711617682711221e-05f, 2.1243064111331478e-05f, 3.521355756674893e-05f, 3.22841624438297e-05f, 2.380825208092574e-05f, 2.2316935428534634e-05f, 5.014414637116715e-05f, 3.2908956200117245e-05f, 5.046645674156025e-05f, 2.4077493435470387e-05f, 4.727303530671634e-05f, 4.6317589294631034e-05f, 2.721971395658329e-05f, 3.708861913764849e-05f, 4.7804758651182055e-05f, 3.7271911423886195e-05f, 5.011140092392452e-05f, 3.793383075390011e-05f, 2.904851862695068e-05f, 4.5563887397293e-05f, 4.479169365367852e-05f, 3.62599894287996e-05f, 2.3656963094254024e-05f, 1.946322481671814e-05f, 3.329560058773495e-05f, 2.5807075871853158e-05f, 4.4034131860826164e-05f, 3.420374196139164e-05f, 2.9974540666444227e-05f, 2.6178191546932794e-05f, 2.088506516884081e-05f, 3.693678809213452e-05f, 3.9235761505551636e-05f, 3.118184395134449e-05f, 4.0985760278999805e-05f, 4.761468153446913e-05f, 1.6348978533642367e-05f, 3.5191937058698386e-05f, 3.479561200947501e-05f, 2.2581736629945226e-05f, 1.8979390006279573e-05f, 4.440475458977744e-05f, 2.8635440685320646e-05f, 3.441762237343937e-05f, 4.10492139053531e-05f, 2.4976447093649767e-05f, 4.248408367857337e-05f, 3.1980787753127515e-05f, 6.048510113032535e-05f, 2.945421147160232e-05f, 3.903025935869664e-05f, 4.302024171920493e-05f, 2.8549704438773915e-05f, 4.9371148634236306e-05f, 4.256270040059462e-05f, 5.0721082516247407e-05f, 1.544996484881267e-05f, 4.054715464008041e-05f, 1.5037004231999163e-05f, 3.6549339711200446e-05f, 4.240989437676035e-05f, 2.133126872649882e-05f, 3.757576268981211e-05f, 3.8969319575699046e-05f, 1.8933076717075892e-05f, 2.716915332712233e-05f, 3.421827204874717e-05f, 4.3268006265861914e-05f, 3.84034174203407e-05f, 5.790733848698437e-05f, 2.7912879886571318e-05f, 3.234261748730205e-05f, 2.7291514925309457e-05f, 3.2847798138391227e-05f, 3.009551619470585e-05f, 3.9606653444934636e-05f, 2.2463224013336003e-05f, 1.707703631836921e-05f, 4.3094027205370367e-05f, 2.806491647788789e-05f, 2.254813807667233e-05f, 1.7683234545984305e-05f, 5.2327977755339816e-05f, 5.304050137056038e-05f, 2.3087181034497917e-05f, 4.195207293378189e-05f, 2.213466177636292e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002376783872023225f, 0.0012850548373535275f, 0.003035407280549407f, 0.002227105898782611f, 0.001409037271514535f, 0.002077561803162098f, 0.002510238206014037f, 0.004344155080616474f, 0.0018627059180289507f, 0.0023165768943727016f, 0.0037210818845778704f, 0.001323771313764155f, 0.001998619642108679f, 0.0018468870548531413f, 0.003116867272183299f, 0.0014880368253216147f, 0.00272779050283134f, 0.0033564537297934294f, 0.0009680315852165222f, 0.003535613650456071f, 0.0011527793249115348f, 0.0026246258057653904f, 0.003111734287813306f, 0.0035264468751847744f, 0.0013415685389190912f, 0.0018627423560246825f, 0.0014033870538696647f, 0.002860512351617217f, 0.0032410239800810814f, 0.003114724066108465f, 0.0014734746655449271f, 0.0010125795379281044f, 0.0017969626933336258f, 0.0024614783469587564f, 0.003074763808399439f, 0.0018453457159921527f, 0.0015575543511658907f, 0.0025370283983647823f, 0.002720416756346822f, 0.0014695230638608336f, 0.001891172956675291f, 0.00268292217515409f, 0.00317509938031435f, 0.002040342427790165f, 0.002397205214947462f, 0.002107898937538266f, 0.0012350839097052813f, 0.0016965888207778335f, 0.001427029143087566f, 0.002381247701123357f, 0.0022918996401131153f, 0.00170836818870157f, 0.0012032309314236045f, 0.002141266595572233f, 0.0023694008123129606f, 0.0014258113224059343f, 0.001874083885923028f, 0.0014557397225871682f, 0.0020264049526304007f, 0.002702581463381648f, 0.001339385868050158f, 0.003166269278153777f, 0.0015486649936065078f, 0.0023348794784396887f, 0.0011784014059230685f, 0.0018775396747514606f, 0.0015796899097040296f, 0.0023663132451474667f, 0.0025095378514379263f, 0.0027794502675533295f, 0.002126797568053007f, 0.0015683135716244578f, 0.0011780366767197847f, 0.0012525373604148626f, 0.0014819810166954994f, 0.002189986640587449f, 0.0020516442600637674f, 0.0020978283137083054f, 0.0017912329640239477f, 0.0017923919949680567f, 0.0033008684404194355f, 0.002403899561613798f, 0.002635803772136569f, 0.0014645447954535484f, 0.001981318462640047f, 0.0027343688998371363f, 0.002486809156835079f, 0.0023013632744550705f, 0.002044589025899768f, 0.004217742010951042f, 0.0031838284339755774f, 0.002001401036977768f, 0.0013598393416032195f, 0.0018456984544172883f, 0.0028251323383301497f, 0.0016305483877658844f, 0.0027874659281224012f, 0.0019375717965885997f, 0.0037040316965430975f, 0.0017193114617839456f, 0.002299213083460927f, 0.0016015806468203664f, 0.0027597148437052965f, 0.0014035777421668172f, 0.0029258958529680967f, 0.0017249762313440442f, 0.0035723859909921885f, 0.0026818299666047096f, 0.002605499466881156f, 0.002484146738424897f, 0.002408002968877554f, 0.001245897146873176f, 0.0019905369263142347f, 0.002154526300728321f, 0.002226591110229492f, 0.0015953104011714458f, 0.001517105964012444f, 0.0034562889486551285f, 0.003253013826906681f, 0.00354210939258337f, 0.0022086072713136673f, 0.0018655742751434445f, 0.0025859365705400705f, 0.0027466360479593277f, 0.001905979122966528f, 0.0009747564326971769f, 0.0018064536852762103f, 0.0012111536925658584f, 0.002662778366357088f, 0.00237322342582047f, 0.003117771353572607f, 0.003351867198944092f, 0.0021813770290464163f, 0.0016993565950542688f, 0.0022173128090798855f, 0.0025784370955079794f, 0.0025050274562090635f, 0.002767654601484537f, 0.0025514920707792044f, 0.002563521033152938f, 0.002246598480269313f, 0.002190403640270233f, 0.001673258957453072f, 0.0027523476164788008f, 0.001057356595993042f, 0.001780005288310349f, 0.0017423416720703244f, 0.0029054884798824787f, 0.0012425067834556103f, 0.0010993217583745718f, 0.00254781823605299f, 0.0021932926028966904f, 0.0012795914663001895f, 0.0010290967766195536f, 0.0022135532926768064f, 0.0024601600598543882f, 0.0016515576280653477f, 0.003233389463275671f, 0.0013022710336372256f, 0.0026499510277062654f, 0.001608717953786254f, 0.00146546121686697f, 0.0023316340520977974f, 0.0008916143560782075f, 0.002817538334056735f, 0.0026090003084391356f, 0.0016071937279775739f, 0.002656014636158943f, 0.0024908380582928658f, 0.0025169209111481905f, 0.0014405339024960995f, 0.0023879006039351225f, 0.0021892525255680084f, 0.0016144843539223075f, 0.001513355178758502f, 0.003400373039767146f, 0.0022316209506243467f, 0.003422229550778866f, 0.0016327421180903912f, 0.0032056772615760565f, 0.0031408867798745632f, 0.0018458223203197122f, 0.0025150522124022245f, 0.003241734579205513f, 0.002527481410652399f, 0.003398152533918619f, 0.0025723676662892103f, 0.0019698371179401875f, 0.0030897767283022404f, 0.003037412650883198f, 0.0024588610976934433f, 0.001604225137270987f, 0.001319839502684772f, 0.002257840009406209f, 0.001750028459355235f, 0.002986040897667408f, 0.0023194230161607265f, 0.0020326324738562107f, 0.0017751945415511727f, 0.0014162572333589196f, 0.0025047562085092068f, 0.00266065401956439f, 0.00211450201459229f, 0.0027793250046670437f, 0.0032288450747728348f, 0.001108656288124621f, 0.002386434469372034f, 0.002359558828175068f, 0.0015313118929043412f, 0.0012870297068729997f, 0.0030111735686659813f, 0.001941825496032834f, 0.0023339265026152134f, 0.002783627714961767f, 0.0016937019536271691f, 0.0028809290379285812f, 0.00216868007555604f, 0.004101613536477089f, 0.0019973479211330414f, 0.0026467186398804188f, 0.0029172871727496386f, 0.0019360114820301533f, 0.0033479544799774885f, 0.0028862603940069675f, 0.003439496271312237f, 0.0010476924944669008f, 0.0027495822869241238f, 0.0010196887888014317f, 0.002478482434526086f, 0.002875898266211152f, 0.0014465152053162456f, 0.0025480862241238356f, 0.0026425861287862062f, 0.0012838890543207526f, 0.0018423936562612653f, 0.002320408122614026f, 0.0029340884648263454f, 0.002604211214929819f, 0.003926810342818499f, 0.0018928272183984518f, 0.0021932164672762156f, 0.0018506912747398019f, 0.002227473771199584f, 0.002040836028754711f, 0.0026858048513531685f, 0.0015232752775773406f, 0.001158027327619493f, 0.00292229070328176f, 0.001903137075714767f, 0.0015290335286408663f, 0.0011991348583251238f, 0.003548462875187397f, 0.003596780588850379f, 0.001565587124787271f, 0.0028448523953557014f, 0.001500994898378849f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.273964729392901e-05f, 0.00018584085046313703f, 0.00013081439828965813f, 0.00010575528722256422f, 0.00017669249791651964f, 6.735414353897795e-05f, 5.3636420489056036e-05f, 0.00010662329441402107f, 8.904738933779299e-05f, 8.054802310653031e-05f, 6.338203093037009e-05f, 6.0641403251793236e-05f, 8.325037197209895e-05f, 0.00013670478074345738f, 5.518909892998636e-05f, 0.00011374670430086553f, 0.00014737987658008933f, 5.5922304454725236e-05f, 7.128073775675148e-05f, 6.651340663665906e-05f, 0.0001468042319174856f, 9.70008404692635e-05f, 6.977971497690305e-05f, 5.674072235706262e-05f, 6.669144204352051e-05f, 6.512872641906142e-05f, 6.076750287320465e-05f, 7.77887471485883e-05f, 8.87580172275193e-05f, 5.3714717068942264e-05f, 0.00016000385221559554f, 6.851620128145441e-05f, 6.119895988376811e-05f, 6.393474905053154e-05f, 5.087088356958702e-05f, 8.384344982914627e-05f, 7.178679516073316e-05f, 9.165411756839603e-05f, 0.00011210369120817631f, 5.1848095608875155e-05f, 6.890774238854647e-05f, 6.0766629758290946e-05f, 6.591770943487063e-05f, 5.924408105784096e-05f, 5.353917003958486e-05f, 5.577117917709984e-05f, 0.00014358750195242465f, 8.74675897648558e-05f, 0.00015735447232145816f, 4.411788177094422e-05f, 0.00014433209435082972f, 0.00013894749281462282f, 0.0002214249543612823f, 0.00016378208238165826f, 0.00011224378977203742f, 0.00013990137085784227f, 7.6184885983821e-05f, 8.317484753206372e-05f, 7.348454528255388e-05f, 8.996768883662298e-05f, 0.00012932236131746322f, 6.0218924772925675e-05f, 7.108897989382967e-05f, 5.4689153330400586e-05f, 6.857854896225035e-05f, 6.677034252788872e-05f, 0.00016279799456242472f, 6.945357017684728e-05f, 6.581459456356242e-05f, 5.3679479606216773e-05f, 0.00011124888260383159f, 0.00013248853792902082f, 7.340859156101942e-05f, 6.710627349093556e-05f, 9.135172876995057e-05f, 6.842273432994261e-05f, 0.00012189031258458272f, 6.336042861221358e-05f, 6.312054756563157e-05f, 0.0001804595231078565f, 5.618037539534271e-05f, 5.281685298541561e-05f, 5.788463386124931e-05f, 0.00015106797218322754f, 7.484901288989931e-05f, 0.00012343397247605026f, 8.245006756624207e-05f, 0.0001449418195988983f, 8.933168282965198e-05f, 0.00013677403330802917f, 6.397836841642857e-05f, 6.935284909559414e-05f, 7.497223850805312e-05f, 8.938834798755124e-05f, 4.923599772155285e-05f, 0.00017177668632939458f, 6.569937249878421e-05f, 8.265971700893715e-05f, 7.072197331581265e-05f, 7.061030919430777e-05f, 6.15989847574383e-05f, 0.00015410143532790244f, 6.0890393797308207e-05f, 4.8817637434694916e-05f, 9.82988640316762e-05f, 7.048311817925423e-05f, 0.00014354896848089993f, 0.0001193483840324916f, 6.54871910228394e-05f, 5.520101331057958e-05f, 8.558386616641656e-05f, 6.386266613844782e-05f, 8.593819075031206e-05f, 5.85174529987853e-05f, 5.134125240147114e-05f, 0.00011317271128064021f, 0.00011804889072664082f, 5.7721514167496935e-05f, 6.926473724888638e-05f, 8.181537123164162e-05f, 0.00011991537030553445f, 9.668472921475768e-05f, 5.834270268678665e-05f, 6.053135439287871e-05f, 6.005853720125742e-05f, 7.451943383784965e-05f, 6.73175891279243e-05f, 5.6678123655728996e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0034152718726545572f, 0.008725599385797977f, 0.006141997873783112f, 0.004965422209352255f, 0.008296065963804722f, 0.00316241174004972f, 0.002518337219953537f, 0.005006176885217428f, 0.0041809529066085815f, 0.0037818909622728825f, 0.002975913230329752f, 0.002847235184162855f, 0.003908771555870771f, 0.006418562959879637f, 0.0025912385899573565f, 0.005340635310858488f, 0.006919780280441046f, 0.002625663997605443f, 0.0033467733301222324f, 0.003122937399893999f, 0.00689275236800313f, 0.004554383456707001f, 0.0032762971241027117f, 0.0026640903670340776f, 0.003131296718493104f, 0.0030579238664358854f, 0.0028531558346003294f, 0.0036523372400552034f, 0.004167366307228804f, 0.002522013382986188f, 0.007512500975281f, 0.0032169728074222803f, 0.002873413497582078f, 0.0030018645338714123f, 0.0023884896654635668f, 0.003936617635190487f, 0.00337053369730711f, 0.004303344059735537f, 0.005263492465019226f, 0.0024343717377632856f, 0.003235356416553259f, 0.0028531148564070463f, 0.0030949681531637907f, 0.0027816281653940678f, 0.002513771178200841f, 0.0026185684837400913f, 0.006741720717400312f, 0.004106778185814619f, 0.007388107478618622f, 0.0020714227575808764f, 0.006776680704206228f, 0.0065238624811172485f, 0.01039634458720684f, 0.007689896505326033f, 0.005270070396363735f, 0.00656864931806922f, 0.0035770328249782324f, 0.003905225545167923f, 0.0034502462949603796f, 0.004224163014441729f, 0.006071943324059248f, 0.00282739894464612f, 0.0033377697691321373f, 0.0025677650701254606f, 0.0032199001871049404f, 0.003135001054033637f, 0.0076436917297542095f, 0.0032609840855002403f, 0.003090126905590296f, 0.0025203588884323835f, 0.005223357584327459f, 0.006220601964741945f, 0.003446680260822177f, 0.003150773700326681f, 0.004289146512746811f, 0.0032125841826200485f, 0.0057229939848184586f, 0.0029748990200459957f, 0.0029636358376592398f, 0.008472935296595097f, 0.0026377809699624777f, 0.0024798568338155746f, 0.002717799274250865f, 0.007092943415045738f, 0.0035143110435456038f, 0.005795471835881472f, 0.0038711954839527607f, 0.006805308163166046f, 0.004194301087409258f, 0.006421814206987619f, 0.0030039125122129917f, 0.0032562550622969866f, 0.003520096419379115f, 0.004196961876004934f, 0.002311728661879897f, 0.008065259084105492f, 0.0030847168527543545f, 0.003881039097905159f, 0.003320538206025958f, 0.0033152953255921602f, 0.0028921954799443483f, 0.007235370576381683f, 0.0028589258436113596f, 0.0022920856717973948f, 0.004615328274667263f, 0.003309323452413082f, 0.0067399111576378345f, 0.005603645462542772f, 0.0030747547280043364f, 0.0025917980819940567f, 0.004018333740532398f, 0.002998479874804616f, 0.0040349699556827545f, 0.0027475114911794662f, 0.002410574583336711f, 0.005313685163855553f, 0.0055426317267119884f, 0.0027101405430585146f, 0.0032521181274205446f, 0.003841395489871502f, 0.005630266387015581f, 0.004539541434496641f, 0.002739306539297104f, 0.0028420682065188885f, 0.002819868503138423f, 0.0034988366533070803f, 0.0031606953125447035f, 0.002661151345819235f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.734590766020119e-05f, 1.3790424418402836e-05f, 1.7207610653713346e-05f, 2.2975938918534666e-05f, 1.4850255865894724e-05f, 5.019528543925844e-05f, 6.648638373007998e-05f, 2.2031394109944813e-05f, 3.860310971504077e-05f, 5.697512824553996e-05f, 4.908304617856629e-05f, 6.363642023643479e-05f, 6.0617836425080895e-05f, 2.6999103283742443e-05f, 3.910478699253872e-05f, 2.7250947823631577e-05f, 1.6946574760368094e-05f, 4.7367142542498186e-05f, 6.134749855846167e-05f, 5.004855484003201e-05f, 1.791758040781133e-05f, 4.7479636123171076e-05f, 6.0823545936727896e-05f, 6.53046736260876e-05f, 4.639738835976459e-05f, 7.698731496930122e-05f, 6.425115861929953e-05f, 5.928348400630057e-05f, 4.6848519559716806e-05f, 5.496578523889184e-05f, 1.6807447536848485e-05f, 5.2378152759047225e-05f, 4.605244976119138e-05f, 3.273183756391518e-05f, 5.6153283367166296e-05f, 2.884865170926787e-05f, 3.5974400816485286e-05f, 4.7044886741787195e-05f, 2.2877642550156452e-05f, 4.02418700105045e-05f, 3.6534329410642385e-05f, 4.143484329688363e-05f, 3.2892105082282797e-05f, 6.719634984619915e-05f, 9.419542766408995e-05f, 5.468167728395201e-05f, 1.738236824166961e-05f, 5.926634548814036e-05f, 1.416159011569107e-05f, 7.712025399086997e-05f, 1.6714997400413267e-05f, 2.2268302927841432e-05f, 1.2494278053054586e-05f, 1.2019689165754244e-05f, 2.0189268980175257e-05f, 1.6192183466046117e-05f, 4.936530240229331e-05f, 4.876856110058725e-05f, 4.936748882755637e-05f, 4.261867070454173e-05f, 2.1642563297064044e-05f, 3.975434083258733e-05f, 5.99915292696096e-05f, 3.644687603809871e-05f, 2.9717710276599973e-05f, 4.546026684693061e-05f, 1.3882407984056044e-05f, 4.4415970478439704e-05f, 5.668626181432046e-05f, 3.8497269997606054e-05f, 1.7945920262718573e-05f, 4.498264388530515e-05f, 5.0378948799334466e-05f, 4.8307872930308804e-05f, 2.8133170417277142e-05f, 4.507055928115733e-05f, 2.929165020759683e-05f, 6.873023812659085e-05f, 5.618469731416553e-05f, 1.8346254364587367e-05f, 4.411195550346747e-05f, 5.712953134207055e-05f, 5.336588219506666e-05f, 2.996032162627671e-05f, 5.460366082843393e-05f, 2.503149698895868e-05f, 4.830748730455525e-05f, 2.0304558347561397e-05f, 2.8956106689292938e-05f, 2.2334750610752963e-05f, 4.641726263798773e-05f, 5.117213731864467e-05f, 4.4436234020395204e-05f, 4.9165453674504533e-05f, 5.321241042111069e-05f, 1.3126685189490672e-05f, 5.270637120702304e-05f, 4.0070877730613574e-05f, 5.072193016530946e-05f, 6.686972483294085e-05f, 4.349886512500234e-05f, 1.8930368241854012e-05f, 4.3211850424995646e-05f, 6.73976173857227e-05f, 2.4885081074899063e-05f, 3.5629142075777054e-05f, 1.4886545613990165e-05f, 4.196677764412016e-05f, 4.344130138633773e-05f, 4.116384297958575e-05f, 6.89630614942871e-05f, 4.4394128053681925e-05f, 3.691483289003372e-05f, 7.141368405427784e-05f, 4.15459944633767e-05f, 1.8301900126971304e-05f, 1.7782887880457565e-05f, 3.972095873905346e-05f, 5.319856063579209e-05f, 4.9738340749172494e-05f, 2.362455052207224e-05f, 4.031949720229022e-05f, 4.548756987787783e-05f, 5.241559483692981e-05f, 6.05922905378975e-05f, 4.9187456170329824e-05f, 6.330854375846684e-05f, 5.6094093451974913e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002559819957241416f, 0.0007455977611243725f, 0.0009303525439463556f, 0.0012422249419614673f, 0.0008028989541344345f, 0.0027138753794133663f, 0.0035946755670011044f, 0.0011911567999050021f, 0.0020871288143098354f, 0.0030804367270320654f, 0.002653740579262376f, 0.003440588479861617f, 0.0032773844432085752f, 0.0014597426634281874f, 0.0021142526529729366f, 0.0014733589487150311f, 0.0009162392234429717f, 0.002560968045145273f, 0.0033168348018079996f, 0.002705942140892148f, 0.0009687379933893681f, 0.0025670500472187996f, 0.003288506530225277f, 0.003530784510076046f, 0.0025085369125008583f, 0.004162422381341457f, 0.0034738248214125633f, 0.003205240936949849f, 0.002532928017899394f, 0.0029717988800257444f, 0.0009087171638384461f, 0.0028318949043750763f, 0.002489887410774827f, 0.001769690657965839f, 0.0030360023956745863f, 0.001559740980155766f, 0.0019450042163953185f, 0.002543544862419367f, 0.001236910349689424f, 0.0021757306531071663f, 0.0019752774387598038f, 0.002240230329334736f, 0.0017783557996153831f, 0.0036330604925751686f, 0.005092801991850138f, 0.002956438111141324f, 0.0009398010442964733f, 0.0032043142709881067f, 0.0007656653178855777f, 0.004169609863311052f, 0.0009037187555804849f, 0.0012039656285196543f, 0.0006755198701284826f, 0.0006498605944216251f, 0.0010915598832070827f, 0.0008754520677030087f, 0.002669001230970025f, 0.0026367376558482647f, 0.0026691195089370012f, 0.0023042354732751846f, 0.0011701341718435287f, 0.002149371663108468f, 0.003243522485718131f, 0.001970549114048481f, 0.0016067278338596225f, 0.0024578701704740524f, 0.0007505709654651582f, 0.0024014089722186327f, 0.0030648186802864075f, 0.0020814065355807543f, 0.0009702701936475933f, 0.0024320469237864017f, 0.00272380537353456f, 0.002611829899251461f, 0.0015210575656965375f, 0.0024368001613765955f, 0.0015836922684684396f, 0.0037159924395382404f, 0.0030377008952200413f, 0.000991914770565927f, 0.002384972060099244f, 0.0030887846369296312f, 0.0028852978721261024f, 0.0016198449302464724f, 0.0029522201512008905f, 0.0013533614110201597f, 0.002611808944493532f, 0.0010977931087836623f, 0.0015655506867915392f, 0.0012075582053512335f, 0.002509611425921321f, 0.002766690216958523f, 0.002402504440397024f, 0.0026581960264593363f, 0.002877000253647566f, 0.0007097118068486452f, 0.0028496405575424433f, 0.002166485646739602f, 0.0027423491701483727f, 0.003615401219576597f, 0.00235182442702353f, 0.0010234956862404943f, 0.0023363064974546432f, 0.0036439422983676195f, 0.00134544528555125f, 0.001926337368786335f, 0.0008048610179685056f, 0.002268990036100149f, 0.0023487121798098087f, 0.002225578296929598f, 0.0037285801954567432f, 0.0024002280551940203f, 0.0019958498887717724f, 0.0038610766641795635f, 0.002246239921078086f, 0.000989516731351614f, 0.0009614556911401451f, 0.0021475667599588633f, 0.002876251470297575f, 0.002689169952645898f, 0.0012772929621860385f, 0.002179927658289671f, 0.002459346316754818f, 0.0028339193668216467f, 0.0032760032918304205f, 0.0026593857910484076f, 0.0034228612203150988f, 0.0030328023713082075f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011696797446347773f, 0.0001789239322533831f, 0.0001118653453886509f, 9.571723057888448e-05f, 8.393831376451999e-05f, 0.00014778277545701712f, 7.978617213666439e-05f, 0.00010953471064567566f, 0.0003026284684892744f, 0.00012827296450268477f, 0.0001312912645516917f, 0.00010476793249836192f, 6.515494897030294e-05f, 0.0001133340410888195f, 0.00011972348147537559f, 6.31465227343142e-05f, 0.00010793716501211748f, 0.00013944253441877663f, 0.00028195726918056607f, 0.00012355447688605636f, 9.89826294244267e-05f, 0.00019400744349695742f, 0.00010172000474995002f, 6.160904740681872e-05f, 0.0001162148400908336f, 7.77227251091972e-05f, 6.525566277559847e-05f, 0.0001844759681262076f, 8.71220909175463e-05f, 6.659950304310769e-05f, 9.872181544778869e-05f, 6.527197547256947e-05f, 0.00010890092380577698f, 9.880807920126244e-05f, 7.959603681229055e-05f, 0.00013317893899511546f, 0.0001273950474569574f, 0.00011094962246716022f, 0.00019121998047921807f, 8.439155499218032e-05f, 7.451890269294381e-05f, 0.00015764198906254023f, 7.74709988036193e-05f, 9.369328472530469e-05f, 0.00016033169231377542f, 0.0001105598930735141f, 0.00011160079156979918f, 0.00012862862786278129f, 0.00012258974311407655f, 8.641089516459033e-05f, 0.0003112634876742959f, 0.00015477309352718294f, 8.325510862050578e-05f, 3.9451442717108876e-05f, 0.00015425281890202314f, 7.732076483080164e-05f, 8.429523586528376e-05f, 0.0001643546565901488f, 0.00011811915464932099f, 0.00010373966506449506f, 0.0001458445331081748f, 0.0001381435722578317f, 0.00011474422353785485f, 7.548707071691751e-05f, 8.005225390661508e-05f, 0.00011012121831299737f, 0.00014725672372151166f, 0.00011923405691049993f, 0.0001335865817964077f, 0.00011389615974621847f, 0.00013215515355113894f, 0.00021915322577115148f, 0.00010694107913877815f, 0.00014397071208804846f, 7.414422725560144e-05f, 0.00017430578009225428f, 0.00011305530642857775f, 8.68591305334121e-05f, 0.0001763968903105706f, 9.089399100048468e-05f, 7.552901661256328e-05f, 6.714771006954834e-05f, 0.00019103371596429497f, 8.322894427692518e-05f, 0.00010212133202003315f, 0.00025089559494517744f, 0.0001986605057027191f, 8.519885886926204e-05f, 0.00016592619067523628f, 5.0543992983875796e-05f, 8.771856664679945e-05f, 9.804790170164779e-05f, 0.0002108178159687668f, 0.0001958708162419498f, 6.876188854221255e-05f, 0.00011274165444774553f, 0.00014754898438695818f, 0.00015878962585702538f, 8.190146763809025e-05f, 9.129619866143912e-05f, 0.000159683360834606f, 0.00011689800885505974f, 0.00010403766646049917f, 0.00023053286713548005f, 8.582607551943511e-05f, 0.00011152516526635736f, 0.0003722917172126472f, 0.00013148985453881323f, 0.00022301838907878846f, 0.0001066426484612748f, 0.00010890275007113814f, 7.913340959930792e-05f, 0.00012748828157782555f, 0.0001057768240571022f, 6.205530371516943e-05f, 0.00011737414024537429f, 6.1961000028532e-05f, 0.00010959240171359852f, 0.00014476144860964268f, 9.975190187105909e-05f, 0.00010559011570876464f, 7.373424159595743e-05f, 0.0001283798919757828f, 0.0001295512483920902f, 0.00011590606300160289f, 0.00017112924251705408f, 7.160948007367551e-05f, 0.0001721260487101972f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004971138667315245f, 0.007604266982525587f, 0.004754276946187019f, 0.004067982081323862f, 0.003567378269508481f, 0.006280767731368542f, 0.0033909121993929148f, 0.0046552252024412155f, 0.012861710041761398f, 0.00545160099864006f, 0.005579878576099873f, 0.004452636931091547f, 0.00276908534578979f, 0.004816696513444185f, 0.005088247824460268f, 0.0026837270706892014f, 0.004587329458445311f, 0.005926307290792465f, 0.011983183212578297f, 0.0052510653622448444f, 0.004206761717796326f, 0.008245316334068775f, 0.004323100205510855f, 0.0026183845475316048f, 0.004939130507409573f, 0.00330321560613811f, 0.0027733654715120792f, 0.007840228267014027f, 0.003702688729390502f, 0.0028304788284003735f, 0.004195677116513252f, 0.0027740588411688805f, 0.004628289025276899f, 0.004199343267828226f, 0.00338283134624362f, 0.0056601050309836864f, 0.0054142894223332405f, 0.004715358838438988f, 0.008126849308609962f, 0.0035866410471498966f, 0.0031670532189309597f, 0.006699784193187952f, 0.003292517503723502f, 0.003981964662671089f, 0.006814096588641405f, 0.0046987952664494514f, 0.004743033554404974f, 0.005466716829687357f, 0.005210063885897398f, 0.0036724628880620003f, 0.013228697702288628f, 0.006577856373041868f, 0.003538341959938407f, 0.001676686224527657f, 0.0065557449124753475f, 0.0032861323561519384f, 0.0035825474187731743f, 0.0069850729778409f, 0.00502006383612752f, 0.00440893555060029f, 0.00619839271530509f, 0.005871101748198271f, 0.004876629449427128f, 0.0032082004472613335f, 0.0034022207837551832f, 0.0046801515854895115f, 0.0062584104016423225f, 0.005067447200417519f, 0.005677429493516684f, 0.0048405868001282215f, 0.005616593640297651f, 0.00931401178240776f, 0.004544995725154877f, 0.006118754856288433f, 0.003151129698380828f, 0.007407995406538248f, 0.004804850555956364f, 0.00369151309132576f, 0.007496867794543505f, 0.0038629944901913404f, 0.0032099829986691475f, 0.002853777725249529f, 0.008118933066725731f, 0.003537229960784316f, 0.004340156447142363f, 0.010663062334060669f, 0.008443071506917477f, 0.003620951436460018f, 0.007051863241940737f, 0.002148119732737541f, 0.0037280390970408916f, 0.004167035687714815f, 0.008959757164120674f, 0.008324509486556053f, 0.0029223801102489233f, 0.004791520070284605f, 0.0062708319164812565f, 0.006748558953404427f, 0.0034808123018592596f, 0.0038800884503871202f, 0.006786542944610119f, 0.004968165419995785f, 0.004421600606292486f, 0.009797646664083004f, 0.0036476082168519497f, 0.004739819560199976f, 0.01582239754498005f, 0.005588318686932325f, 0.009478281252086163f, 0.004532312508672476f, 0.00462836679071188f, 0.0033631697297096252f, 0.005418251734226942f, 0.004495515022426844f, 0.002637350233271718f, 0.004988400731235743f, 0.002633342519402504f, 0.004657676909118891f, 0.006152361165732145f, 0.004239455796778202f, 0.0044875796884298325f, 0.0031337051186710596f, 0.005456145387142897f, 0.005505927838385105f, 0.004926007706671953f, 0.0072729927487671375f, 0.0030434029176831245f, 0.007315356750041246f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.496088023297489e-05f, 7.704577001277357e-05f, 6.105026113800704e-05f, 5.5184500524774194e-05f, 5.717987733078189e-05f, 6.433283851947635e-05f, 4.787291254615411e-05f, 2.2313846784527414e-05f, 2.1371270122472197e-05f, 4.7871006245259196e-05f, 5.177959246793762e-05f, 2.567137016740162e-05f, 5.01683316542767e-05f, 4.719344724435359e-05f, 3.308224040665664e-05f, 4.331715899752453e-05f, 6.753117486368865e-05f, 6.370495248120278e-05f, 2.284441507072188e-05f, 5.798108395538293e-05f, 4.8685091314837337e-05f, 3.849104905384593e-05f, 4.9725218559615314e-05f, 6.338443927234039e-05f, 4.9330734327668324e-05f, 6.263410614337772e-05f, 6.285258132265881e-05f, 3.936095890821889e-05f, 2.8988035410293378e-05f, 5.661613613483496e-05f, 6.172798748593777e-05f, 6.372491043293849e-05f, 5.3717816626885906e-05f, 7.531728624599054e-05f, 5.5589491239516065e-05f, 5.927204983890988e-05f, 6.067240610718727e-05f, 7.970253500388935e-05f, 3.988353637396358e-05f, 9.93180728983134e-05f, 3.871647277264856e-05f, 4.112042734050192e-05f, 5.023770427214913e-05f, 6.854112143628299e-05f, 5.565634637605399e-05f, 4.743086901726201e-05f, 0.00010082314111059532f, 6.832321378169581e-05f, 8.016340871108696e-05f, 4.183995770290494e-05f, 3.086445576627739e-05f, 3.7623278331011534e-05f, 5.250409594736993e-05f, 5.289694672683254e-05f, 3.259829099988565e-05f, 4.9343143473379314e-05f, 5.0965962145710364e-05f, 2.8228691007825546e-05f, 6.516348366858438e-05f, 2.5230416213162243e-05f, 6.426045001717284e-05f, 2.988930827996228e-05f, 2.9106951842550188e-05f, 5.608643914456479e-05f, 2.9245504265418276e-05f, 7.668942998861894e-05f, 3.823006773018278e-05f, 5.855042763869278e-05f, 6.601410859730095e-05f, 8.065857400652021e-05f, 4.38809729530476e-05f, 0.00011042664846172556f, 3.616018875618465e-05f, 9.231277363141999e-05f, 4.743401223095134e-05f, 5.821053855470382e-05f, 5.4059102694736794e-05f, 5.651902029057965e-05f, 3.6401146644493565e-05f, 4.314550824346952e-05f, 3.772527998080477e-05f, 8.531409548595548e-05f, 7.50343460822478e-05f, 6.507841317215934e-05f, 5.05695934407413e-05f, 2.243005837954115e-05f, 3.529194145812653e-05f, 4.6461893361993134e-05f, 3.7444337067427114e-05f, 5.909758328925818e-05f, 4.330515002948232e-05f, 4.501436706050299e-05f, 2.7848363970406353e-05f, 1.7800533896661364e-05f, 7.872104470152408e-05f, 0.00010618034866638482f, 4.3750391341745853e-05f, 3.698291766340844e-05f, 7.843312050681561e-05f, 6.044469409971498e-05f, 3.318970266263932e-05f, 7.103914686013013e-05f, 6.502182804979384e-05f, 3.4564913221402094e-05f, 3.071940227528103e-05f, 5.060932016931474e-05f, 1.964399234566372e-05f, 4.727437408291735e-05f, 4.074909884366207e-05f, 6.672346353298053e-05f, 7.217317761387676e-05f, 6.305846909526736e-05f, 3.0489904020214453e-05f, 5.1247850933577865e-05f, 4.949838694301434e-05f, 5.799415521323681e-05f, 4.203175922157243e-05f, 8.909093594411388e-05f, 5.131703073857352e-05f, 3.843781087198295e-05f, 6.422580918297172e-05f, 5.312374560162425e-05f, 9.521728497929871e-05f, 9.095342102227733e-05f, 6.498119182651863e-05f, 2.317856160516385e-05f, 3.502304753055796e-05f, 4.225514203426428e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004035837482661009f, 0.003274445189163089f, 0.0025946360547095537f, 0.002345341257750988f, 0.0024301446974277496f, 0.002734145615249872f, 0.0020345987286418676f, 0.0009483384783379734f, 0.0009082789765670896f, 0.002034517703577876f, 0.0022006325889378786f, 0.0010910332202911377f, 0.002132154069840908f, 0.002005721442401409f, 0.0014059952227398753f, 0.001840979210101068f, 0.002870074938982725f, 0.002707460429519415f, 0.0009708876023069024f, 0.0024641959462314844f, 0.002069116337224841f, 0.00163586949929595f, 0.0021133217960596085f, 0.0026938386727124453f, 0.0020965561270713806f, 0.0026619494892656803f, 0.0026712347753345966f, 0.0016728407936170697f, 0.0012319914530962706f, 0.0024061857257038355f, 0.002623439533635974f, 0.002708308631554246f, 0.002283007139340043f, 0.0032009845599532127f, 0.0023625532630831003f, 0.0025190620217472315f, 0.002578577259555459f, 0.003387357573956251f, 0.0016950502758845687f, 0.004221017938107252f, 0.0016454500146210194f, 0.0017476181965321302f, 0.002135102404281497f, 0.0029129977338016033f, 0.002365394728258252f, 0.0020158118568360806f, 0.00428498350083828f, 0.002903736662119627f, 0.0034069449175149202f, 0.0017781981732696295f, 0.0013117393245920539f, 0.0015989893581718206f, 0.0022314239758998156f, 0.0022481202613562346f, 0.001385427312925458f, 0.0020970834884792566f, 0.002166053280234337f, 0.0011997193796560168f, 0.002769448095932603f, 0.0010722926817834377f, 0.0027310692239552736f, 0.001270295586436987f, 0.0012370453914627433f, 0.0023836735635995865f, 0.0012429339112713933f, 0.003259300719946623f, 0.001624777913093567f, 0.0024883931037038565f, 0.0028055994771420956f, 0.0034279893152415752f, 0.0018649413250386715f, 0.004693132359534502f, 0.0015368079766631126f, 0.003923292737454176f, 0.002015945501625538f, 0.002473947824910283f, 0.002297511789947748f, 0.0024020583368837833f, 0.0015470486832782626f, 0.0018336840439587831f, 0.0016033243155106902f, 0.0036258490290492773f, 0.003188959788531065f, 0.002765832468867302f, 0.0021492077503353357f, 0.000953277456574142f, 0.0014999074628576636f, 0.0019746304024010897f, 0.0015913842944428325f, 0.0025116472970694304f, 0.0018404688453301787f, 0.0019131106091663241f, 0.0011835554614663124f, 0.0007565226405858994f, 0.003345644334331155f, 0.0045126648619771f, 0.0018593915738165379f, 0.0015717740170657635f, 0.003333407687023282f, 0.0025688994210213423f, 0.0014105623122304678f, 0.003019163617864251f, 0.002763427561149001f, 0.001469008857384324f, 0.0013055745512247086f, 0.00215089600533247f, 0.0008348696283064783f, 0.002009160816669464f, 0.0017318367026746273f, 0.0028357470873743296f, 0.0030673600267618895f, 0.0026799847837537527f, 0.0012958209263160825f, 0.0021780335810035467f, 0.00210368144325912f, 0.0024647514801472425f, 0.001786349806934595f, 0.0037863648030906916f, 0.0021809737663716078f, 0.0016336069675162435f, 0.0027295968029648066f, 0.002257759217172861f, 0.004046734422445297f, 0.0038655204698443413f, 0.0027617006562650204f, 0.0009850888745859265f, 0.0014884794363752007f, 0.0017958434764295816f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.657605940243229e-05f, 0.0001690351782599464f, 6.934234988875687e-05f, 0.0001542455138405785f, 6.356690573738888e-05f, 0.00011855148477479815f, 0.00011566124885575846f, 7.444088259944692e-05f, 0.0001423182839062065f, 0.00012113602133467793f, 0.00014355103485286236f, 0.00015967919898685068f, 6.678629870293662e-05f, 0.00019599370716605335f, 8.718106982996687e-05f, 9.734591003507376e-05f, 7.610006286995485e-05f, 5.023213452659547e-05f, 9.71644331002608e-05f, 0.0001399868488078937f, 8.642533066449687e-05f, 0.00014955084770917892f, 0.00010073256999021396f, 0.00015705196710769087f, 0.00011078304669354111f, 6.893781392136589e-05f, 0.0001040559945977293f, 7.875869778217748e-05f, 9.567069355398417e-05f, 0.00019005841750185937f, 0.00012242030061315745f, 0.00010798992298077792f, 6.19496640865691e-05f, 0.0001035338209476322f, 7.032563735265285e-05f, 9.679877257440239e-05f, 8.372987213078886e-05f, 0.00011374329187674448f, 0.0001293954555876553f, 4.4715448893839493e-05f, 0.00014851902960799634f, 0.00011210074444534257f, 0.00014135506353341043f, 0.0001477856858400628f, 7.969841681187972e-05f, 6.374028453137726e-05f, 0.0002054851793218404f, 0.00011042310507036746f, 0.0002213093830505386f, 0.00012924111797474325f, 0.0001652642386034131f, 0.00030890744528733194f, 0.0002555301762185991f, 0.0001701589353615418f, 9.672909072833136e-05f, 0.00014733185525983572f, 7.673446089029312e-05f, 6.34778625681065e-05f, 0.00010571645543677732f, 7.270577043527737e-05f, 9.173461876343936e-05f, 5.8280355005990714e-05f, 0.00014457025099545717f, 0.00021986922365613282f, 8.402669482165948e-05f, 8.964379230747e-05f, 7.813084084773436e-05f, 0.0001671494246693328f, 6.167971150716767e-05f, 5.6113931350409985e-05f, 0.00011430909944465384f, 0.00010653026401996613f, 0.00020206323824822903f, 0.00014227793144527823f, 0.00011186192568857223f, 9.06880377442576e-05f, 8.083851571427658e-05f, 5.148188938619569e-05f, 0.00011193792306585237f, 4.6179538912838325e-05f, 7.383708725683391e-05f, 0.00013626081636175513f, 0.00013512869190890342f, 0.00015518297732342035f, 5.177081766305491e-05f, 9.14397751330398e-05f, 3.921971801901236e-05f, 8.051845361478627e-05f, 0.00013748003402724862f, 6.487746577477083e-05f, 0.0001344221382169053f, 0.00011345414532115683f, 6.279488297877833e-05f, 0.0001297249982599169f, 0.0001055812172126025f, 7.205905421869829e-05f, 0.00010366398055339232f, 0.00014509400352835655f, 0.00010265503078699112f, 8.521059498889372e-05f, 0.000123253877973184f, 0.00018487093620933592f, 0.00010865941294468939f, 5.847681677551009e-05f, 8.565720781916752e-05f, 0.0001116247585741803f, 0.00011874322080984712f, 6.353150092763826e-05f, 0.00010806682257680222f, 0.00011760367488022894f, 0.00010213776113232598f, 6.55218682368286e-05f, 5.339095514500514e-05f, 0.0002086297608911991f, 0.00010896034655161202f, 0.00010975181794492528f, 4.554281986202113e-05f, 4.968122811987996e-05f, 8.644111221656203e-05f, 0.00014824315439909697f, 0.00011221740714972839f, 7.734115206403658e-05f, 0.00012664902897085994f, 0.0001793099072529003f, 8.293672726722434e-05f, 0.00028843263862654567f, 0.00010578319052001461f, 0.00010669627226889133f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004640265367925167f, 0.009059872478246689f, 0.0037165803369134665f, 0.008267182856798172f, 0.0034070308320224285f, 0.0063540698029100895f, 0.006199160125106573f, 0.003989849239587784f, 0.0076279123313724995f, 0.006492594722658396f, 0.007693985011428595f, 0.008558414876461029f, 0.003579582553356886f, 0.010504784062504768f, 0.004672692157328129f, 0.005217502824962139f, 0.004078777506947517f, 0.0026923196855932474f, 0.005207776091992855f, 0.007502953056246042f, 0.004632186610251665f, 0.008015559986233711f, 0.005399019457399845f, 0.008417601697146893f, 0.005937700625509024f, 0.003694898448884487f, 0.005577147006988525f, 0.004221273586153984f, 0.005127715412527323f, 0.010186666622757912f, 0.006561429239809513f, 0.005787996109575033f, 0.003320350544527173f, 0.005549159832298756f, 0.003769282251596451f, 0.005188177805393934f, 0.004487716592848301f, 0.006096362601965666f, 0.006935280282050371f, 0.0023966387379914522f, 0.00796025712043047f, 0.0060083260759711266f, 0.00757628632709384f, 0.007920951582491398f, 0.004271640442311764f, 0.0034163235686719418f, 0.011013503186404705f, 0.005918408744037151f, 0.011861641891300678f, 0.006927007809281349f, 0.008857759647071362f, 0.01655668392777443f, 0.0136957922950387f, 0.009120102971792221f, 0.005184442736208439f, 0.00789662729948759f, 0.004112779628485441f, 0.003402258502319455f, 0.005666143726557493f, 0.003896851558238268f, 0.00491675129160285f, 0.0031236845534294844f, 0.007748612202703953f, 0.011784452944993973f, 0.0045036254450678825f, 0.004804688040167093f, 0.004187622107565403f, 0.008958800695836544f, 0.0033058819826692343f, 0.003007569583132863f, 0.006126688327640295f, 0.005709761753678322f, 0.01083009596914053f, 0.007625749334692955f, 0.005995525978505611f, 0.004860657267272472f, 0.004332746844738722f, 0.00275930343195796f, 0.005999599117785692f, 0.002475110348314047f, 0.003957487642765045f, 0.007303246762603521f, 0.0072425673715770245f, 0.008317428641021252f, 0.0027747892308980227f, 0.0049009486101567745f, 0.0021020809654146433f, 0.004315592348575592f, 0.007368593942373991f, 0.0034772735089063644f, 0.00720469793304801f, 0.006080864928662777f, 0.003365652170032263f, 0.006952942814677954f, 0.005658895242959261f, 0.0038621893618255854f, 0.005556135904043913f, 0.0077766841277480125f, 0.005502058658748865f, 0.004567079711705446f, 0.006606106646358967f, 0.009908630512654781f, 0.005823879037052393f, 0.0031342145521193743f, 0.004591017030179501f, 0.005982814356684685f, 0.006364346481859684f, 0.003405133029446006f, 0.005792117677628994f, 0.006303269416093826f, 0.005474334582686424f, 0.003511811839416623f, 0.0028616248164325953f, 0.011182045564055443f, 0.005840008147060871f, 0.005882429424673319f, 0.002440983895212412f, 0.0026627923361957073f, 0.004633032251149416f, 0.0079454705119133f, 0.006014578975737095f, 0.004145296756178141f, 0.00678807869553566f, 0.009610572829842567f, 0.00444520590826869f, 0.015459285117685795f, 0.005669720470905304f, 0.005718659609556198f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00014708837261423469f, 3.2731855753809214e-05f, 9.482857421971858e-05f, 6.49522989988327e-05f, 6.26521505182609e-05f, 5.943423821008764e-05f, 3.8976188079686835e-05f, 5.932369458605535e-05f, 5.1571558287832886e-05f, 6.191658030729741e-05f, 6.483597098849714e-05f, 5.7305263908347115e-05f, 5.805785986012779e-05f, 2.341983599762898e-05f, 5.0018403271678835e-05f, 7.363536133198068e-05f, 6.634946475969627e-05f, 3.2229505450231954e-05f, 3.644396929303184e-05f, 7.156200445024297e-05f, 7.270692731253803e-05f, 8.49667630973272e-05f, 3.777278107008897e-05f, 3.1674491765443236e-05f, 8.030731260078028e-05f, 5.1892777264583856e-05f, 7.754192483844236e-05f, 7.54676220822148e-05f, 4.805803473573178e-05f, 3.940312308259308e-05f, 2.490770202712156e-05f, 6.756468792445958e-05f, 5.555035386350937e-05f, 3.679875226225704e-05f, 3.238921271986328e-05f, 3.79288503609132e-05f, 7.349695806624368e-05f, 0.00011335605813656002f, 0.00010479951743036509f, 7.845176151022315e-05f, 7.29285238776356e-05f, 7.217012898763642e-05f, 4.426285522640683e-05f, 3.574883157853037e-05f, 6.218636553967372e-05f, 4.8277463065460324e-05f, 8.31378492875956e-05f, 8.621688175480813e-05f, 4.0404192986898124e-05f, 4.068821363034658e-05f, 4.995440031052567e-05f, 2.453588240314275e-05f, 6.20697028352879e-05f, 3.5746037610806525e-05f, 7.739526336081326e-05f, 5.6157048675231636e-05f, 7.786684727761894e-05f, 7.682055002078414e-05f, 7.292503141798079e-05f, 5.140073335496709e-05f, 6.441545701818541e-05f, 0.00016555712500121444f, 3.8504062104038894e-05f, 3.273904076195322e-05f, 4.282118970877491e-05f, 7.947769336169586e-05f, 4.864689617534168e-05f, 6.920906889718026e-05f, 6.981111073400825e-05f, 4.207260280963965e-05f, 2.9366445232881233e-05f, 3.064669363084249e-05f, 2.033870987361297e-05f, 5.668964149663225e-05f, 3.9330581785179675e-05f, 5.991839861962944e-05f, 6.134916475275531e-05f, 6.033081081113778e-05f, 7.14914858690463e-05f, 8.075720688793808e-05f, 4.331202580942772e-05f, 6.581732304766774e-05f, 7.289469795068726e-05f, 7.495581667171791e-05f, 6.813497748225927e-05f, 3.5585522709880024e-05f, 7.599341915920377e-05f, 7.950370491016656e-05f, 9.70918481471017e-05f, 6.945959466975182e-05f, 5.7059813116211444e-05f, 6.50189831503667e-05f, 6.094150012359023e-05f, 7.470578566426411e-05f, 9.577698801876977e-05f, 4.93757106596604e-05f, 5.4970794735709205e-05f, 5.7246910728281364e-05f, 5.964622687315568e-05f, 5.079685797682032e-05f, 4.510618600761518e-05f, 7.5756230216939e-05f, 0.00011361381621100008f, 4.624248686013743e-05f, 5.6930519349407405e-05f, 2.551445686549414e-05f, 6.320539978332818e-05f, 6.734910857630894e-05f, 6.737143849022686e-05f, 6.155244045658037e-05f, 4.076330878888257e-05f, 6.735564966220409e-05f, 6.651951116509736e-05f, 3.532840855768882e-05f, 4.339594306657091e-05f, 5.103632065583952e-05f, 5.045235593570396e-05f, 6.212280277395621e-05f, 7.848540553823113e-05f, 3.421360088395886e-05f, 4.53439679404255e-05f, 4.846354204346426e-05f, 5.817235796712339e-05f, 4.4000444177072495e-05f, 7.402185292448848e-05f, 2.152562592527829e-05f, 6.579457112820819e-05f, 6.224514072528109e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006904157809913158f, 0.001536395400762558f, 0.004451143555343151f, 0.003048785962164402f, 0.002940819598734379f, 0.0027897744439542294f, 0.0018294972833245993f, 0.002784585580229759f, 0.0024207092355936766f, 0.002906292676925659f, 0.003043325385078788f, 0.0026898428332060575f, 0.0027251688297837973f, 0.0010992999887093902f, 0.002347806002944708f, 0.0034563587978482246f, 0.003114367136731744f, 0.001512815710157156f, 0.0017106377054005861f, 0.0033590376842767f, 0.003412779187783599f, 0.0039882417768239975f, 0.0017730107065290213f, 0.001486763940192759f, 0.0037695325445383787f, 0.002435786882415414f, 0.003639728296548128f, 0.0035423629451543093f, 0.0022557885386049747f, 0.0018495370168238878f, 0.0011691387044265866f, 0.0031714083161205053f, 0.0026074694469571114f, 0.0017272909171879292f, 0.0015203122748062015f, 0.0017803363734856248f, 0.0034498623572289944f, 0.005320802330970764f, 0.004919168073683977f, 0.0036824350245296955f, 0.003423180663958192f, 0.003387582255527377f, 0.002077647252008319f, 0.0016780088189989328f, 0.0029189561028033495f, 0.002266088267788291f, 0.0039023945573717356f, 0.00404692068696022f, 0.001896526082418859f, 0.001909857732243836f, 0.002344801789149642f, 0.0011516859522089362f, 0.002913480158895254f, 0.0016778776189312339f, 0.003632844192907214f, 0.002635946962982416f, 0.003654979635030031f, 0.0036058679688721895f, 0.003423016518354416f, 0.0024126910138875246f, 0.0030235869344323874f, 0.007771060336381197f, 0.0018073362298309803f, 0.0015367327723652124f, 0.0020099771209061146f, 0.0037305911537259817f, 0.002283429028466344f, 0.003248593769967556f, 0.00327685265801847f, 0.001974839251488447f, 0.0013784270267933607f, 0.0014385203830897808f, 0.0009546755463816226f, 0.002660946222022176f, 0.0018461321014910936f, 0.0028125003445893526f, 0.0028796589467674494f, 0.0028318585827946663f, 0.0033557277638465166f, 0.0037906498182564974f, 0.002033016411587596f, 0.0030893890652805567f, 0.0034215927589684725f, 0.0035183392465114594f, 0.0031981770880520344f, 0.0016703432193025947f, 0.003567043226212263f, 0.0037318121176213026f, 0.004557379055768251f, 0.0032603531144559383f, 0.002678321674466133f, 0.003051915904507041f, 0.0028605235274881124f, 0.0035066031850874424f, 0.004495661240071058f, 0.002317638834938407f, 0.0025802655145525932f, 0.0026871038135141134f, 0.0027997249271720648f, 0.002384345745667815f, 0.002117232186719775f, 0.003555909963324666f, 0.005332901142537594f, 0.00217056879773736f, 0.0026722527109086514f, 0.001197619130834937f, 0.002966788364574313f, 0.0031612892635166645f, 0.0031623374670743942f, 0.002889200346544385f, 0.0019133825553581119f, 0.003161596367135644f, 0.003122348804026842f, 0.00165827467571944f, 0.002036955440416932f, 0.0023955858778208494f, 0.0023681751918047667f, 0.002915972610935569f, 0.003684014081954956f, 0.0016059469198808074f, 0.0021283933892846107f, 0.0022748226765543222f, 0.0027305432595312595f, 0.002065330045297742f, 0.0034745000302791595f, 0.0010103880194947124f, 0.0030883210711181164f, 0.002921714913100004f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001625774457352236f, 0.00010977750207530335f, 0.0001240196725120768f, 0.00019386806525290012f, 0.0001182059568236582f, 0.0001558378426125273f, 0.00018378453387413174f, 7.849273242754862e-05f, 9.16504577617161e-05f, 0.00019186381541658193f, 0.00011037394142476842f, 3.482640386209823e-05f, 6.876038969494402e-05f, 0.00010760864097392187f, 0.0002967960899695754f, 0.00011217030260013416f, 8.882252586772665e-05f, 0.00013699554256163538f, 5.406995478551835e-05f, 4.89264348288998e-05f, 0.00013961187505628914f, 0.00018606841331347823f, 0.000106886109279003f, 5.032271292293444e-05f, 0.00026905402773991227f, 0.0001200265105580911f, 0.00013083974772598594f, 0.00013874114665668458f, 4.9487734941067174e-05f, 0.0001465318346163258f, 0.00010272518557030708f, 0.00022413537953980267f, 0.00012415637320373207f, 6.599698099307716e-05f, 5.411552047007717e-05f, 5.944250733591616e-05f, 0.00012370632612146437f, 8.08334443718195e-05f, 9.132816194323823e-05f, 3.6968329368392006e-05f, 4.3395270040491596e-05f, 0.00016661312838550657f, 0.00010237462993245572f, 6.688284338451922e-05f, 0.0002098472905345261f, 0.00017323681095149368f, 9.276634955313057e-05f, 0.00022575867478735745f, 0.00012885518663097173f, 0.00010750631190603599f, 0.00011484908463899046f, 0.0001651875500101596f, 5.178082938073203e-05f, 0.00011166960757691413f, 0.00011873327457578853f, 0.00011570371862035245f, 0.00017057267541531473f, 0.0001726392365526408f, 0.000131952139781788f, 0.00011880171950906515f, 9.913055691868067e-05f, 3.412716250750236e-05f, 0.00025135549367405474f, 5.026608778280206e-05f, 0.00017341783677693456f, 0.00011230884410906583f, 4.8324760427931324e-05f, 9.334815695183352e-05f, 4.912413714919239e-05f, 9.673659224063158e-05f, 0.00013035794836468995f, 5.3001414926256984e-05f, 0.0001267894695047289f, 0.00012183595390524715f, 0.00010515195754123852f, 0.0001938289060490206f, 0.00012595203588716686f, 9.66578591032885e-05f, 0.000126116065075621f, 7.443982758559287e-05f, 0.00015126410289667547f, 6.394467345671728e-05f, 0.00016213640628848225f, 7.1576279879082e-05f, 8.001452079042792e-05f, 6.339148967526853e-05f, 4.1009880078490824e-05f, 0.00014929869212210178f, 0.00024762609973549843f, 0.00012193196744192392f, 0.00013825313362758607f, 7.695858221268281e-05f, 9.753755875863135e-05f, 3.158258550683968e-05f, 0.00020958813547622412f, 9.52893533394672e-05f, 0.00013049000699538738f, 0.00012165102089056745f, 0.0001765274500939995f, 6.122904596850276e-05f, 0.00014601591101381928f, 8.097050886135548e-05f, 6.796469097025692e-05f, 0.00015289649309124798f, 0.00011568392801564187f, 9.85997830866836e-05f, 0.00018427148461341858f, 5.301493001752533e-05f, 0.0001230200141435489f, 5.19048044225201e-05f, 0.0001610572508070618f, 7.549724250566214e-05f, 6.764655699953437e-05f, 0.00016569826402701437f, 0.0001826965162763372f, 0.00018650491256266832f, 0.0001287412305828184f, 0.00011370763240847737f, 0.00012921485176775604f, 5.100193084217608e-05f, 0.0001956396590685472f, 0.00010185430437559262f, 4.649652328225784e-05f, 0.00010182266851188615f, 3.4603202948346734e-05f, 0.00011043332051485777f, 0.0001529422588646412f, 0.00010675911471480504f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009661750867962837f, 0.006523923948407173f, 0.00737031688913703f, 0.011521309614181519f, 0.007024815306067467f, 0.009261226281523705f, 0.010922059416770935f, 0.004664713982492685f, 0.005446658935397863f, 0.011402199044823647f, 0.006559369619935751f, 0.002069684676826f, 0.004086334258317947f, 0.006395031698048115f, 0.017638178542256355f, 0.006666124798357487f, 0.0052785989828407764f, 0.008141454309225082f, 0.003213302232325077f, 0.0029076298233121634f, 0.008296939544379711f, 0.011057786643505096f, 0.006352092605084181f, 0.0029906088020652533f, 0.015989506617188454f, 0.007133008446544409f, 0.0077756242826581f, 0.008245193399488926f, 0.0029409872367978096f, 0.008708182722330093f, 0.006104814819991589f, 0.013320053927600384f, 0.0073784408159554005f, 0.003922108560800552f, 0.0032160100527107716f, 0.0035325854551047087f, 0.007351694628596306f, 0.004803819116204977f, 0.0054275053553283215f, 0.002196976449340582f, 0.002578920451924205f, 0.00990158598870039f, 0.006083981599658728f, 0.003974754363298416f, 0.012470932677388191f, 0.010295222513377666f, 0.0055129751563072205f, 0.013416524045169353f, 0.00765768438577652f, 0.006388950627297163f, 0.006825321353971958f, 0.009816866368055344f, 0.003077262546867132f, 0.0066363695077598095f, 0.007056153379380703f, 0.006876111030578613f, 0.01013689674437046f, 0.010259709320962429f, 0.00784173235297203f, 0.007060220930725336f, 0.005891190841794014f, 0.0020281297620385885f, 0.014937707222998142f, 0.002987243700772524f, 0.01030598022043705f, 0.006674358155578375f, 0.0028718733228743076f, 0.005547550972551107f, 0.0029193791560828686f, 0.005748921073973179f, 0.0077469912357628345f, 0.0031498002354055643f, 0.007534921634942293f, 0.0072405412793159485f, 0.006249034311622381f, 0.011518982239067554f, 0.0074851540848612785f, 0.005744242109358311f, 0.007494902238249779f, 0.00442385533824563f, 0.008989415131509304f, 0.0038001430220901966f, 0.009635540656745434f, 0.004253678489476442f, 0.004755151458084583f, 0.0037672678008675575f, 0.0024371601175516844f, 0.008872613310813904f, 0.014716073870658875f, 0.00724624702706933f, 0.008216191083192825f, 0.004573541227728128f, 0.005796521436423063f, 0.0018769091693684459f, 0.012455531395971775f, 0.005662913434207439f, 0.007754839491099119f, 0.007229550741612911f, 0.01049078069627285f, 0.003638756927102804f, 0.008677522651851177f, 0.004811964463442564f, 0.004039046820253134f, 0.00908642541617155f, 0.006874934770166874f, 0.005859647877514362f, 0.010950997471809387f, 0.00315060350112617f, 0.007310907822102308f, 0.0030846302397549152f, 0.009571407921612263f, 0.004486695863306522f, 0.004020140506327152f, 0.009847217239439487f, 0.010857399553060532f, 0.011083727702498436f, 0.007650912273675203f, 0.006757486145943403f, 0.00767905917018652f, 0.00303097371943295f, 0.011626592837274075f, 0.006053059361875057f, 0.0027632236015051603f, 0.006051179487258196f, 0.0020564200822263956f, 0.006562898401170969f, 0.009089145809412003f, 0.006344545632600784f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.437902341829613e-05f, 2.259015673189424e-05f, 4.3531304982025176e-05f, 3.431430013733916e-05f, 6.944395136088133e-05f, 0.00011219044972676784f, 2.0344170479802415e-05f, 8.900647662812844e-05f, 2.650216265465133e-05f, 1.8548549633123912e-05f, 9.469288488617167e-05f, 7.056081085465848e-05f, 3.940825263271108e-05f, 3.2543179258937016e-05f, 5.23017552040983e-05f, 6.814898370066658e-05f, 7.10056847310625e-05f, 5.298756150295958e-05f, 0.00010300418944098055f, 3.2027935958467424e-05f, 5.450880780699663e-05f, 8.160345169017091e-05f, 5.596665505436249e-05f, 6.93866386427544e-05f, 2.4051751097431406e-05f, 4.818166053155437e-05f, 7.772858953103423e-05f, 4.165920472587459e-05f, 4.694631934398785e-05f, 4.383751002023928e-05f, 4.850187906413339e-05f, 3.680679583339952e-05f, 8.811310544842854e-05f, 8.896477811504155e-05f, 4.709860877483152e-05f, 8.23063455754891e-05f, 8.235760469688103e-05f, 5.256403892417438e-05f, 3.9516264223493636e-05f, 5.686996519216336e-05f, 3.340103285154328e-05f, 2.9863533200114034e-05f, 7.93013532529585e-05f, 6.182579818414524e-05f, 2.9959523089928553e-05f, 3.0989511287771165e-05f, 2.053119351330679e-05f, 2.100798701576423e-05f, 7.979353540576994e-05f, 5.415939085651189e-05f, 3.826099418802187e-05f, 2.331993164261803e-05f, 5.614473047899082e-05f, 7.205865404102951e-05f, 5.191443415242247e-05f, 5.918606257182546e-05f, 3.341379124321975e-05f, 3.6174056731397286e-05f, 5.555372990784235e-05f, 5.38080494152382e-05f, 7.829180685803294e-05f, 5.89298433624208e-05f, 1.9282602806924842e-05f, 4.016515231342055e-05f, 3.15718243655283e-05f, 5.9330308431526646e-05f, 4.9594898882787675e-05f, 7.460814958903939e-05f, 4.7663543227827176e-05f, 6.584137008758262e-05f, 7.772474782541394e-05f, 5.600155418505892e-05f, 6.977676821406931e-05f, 6.176471651997417e-05f, 7.137536886148155e-05f, 1.9451614207355306e-05f, 5.0703860324574634e-05f, 4.5796536142006516e-05f, 3.8129630411276594e-05f, 4.8586145567242056e-05f, 3.119448228972033e-05f, 5.289120599627495e-05f, 4.5532658987212926e-05f, 4.799655653187074e-05f, 5.2493236580630764e-05f, 6.564913201145828e-05f, 5.688739474862814e-05f, 3.8613063225056976e-05f, 1.9596096535678953e-05f, 6.170776032377034e-05f, 4.546964555629529e-05f, 7.936945621622726e-05f, 0.00010421586193842813f, 6.222085357876495e-05f, 3.120063411188312e-05f, 6.913741526659578e-05f, 5.494685683515854e-05f, 4.710991925094277e-05f, 4.707245898316614e-05f, 5.9578738728305325e-05f, 4.137350697419606e-05f, 2.6557436285656877e-05f, 6.303678674157709e-05f, 7.815873686922714e-05f, 6.780774856451899e-05f, 7.320059376070276e-05f, 2.7871368729392998e-05f, 4.2818654037546366e-05f, 7.54125285311602e-05f, 5.2901141316397116e-05f, 2.5481849661446176e-05f, 5.681595575879328e-05f, 9.162187780020759e-05f, 3.410004865145311e-05f, 2.052444870059844e-05f, 1.9663202692754567e-05f, 3.591403583413921e-05f, 2.9025037292740308e-05f, 5.8831974456552416e-05f, 6.513565313071012e-05f, 2.4356502763112076e-05f, 4.7060009819688275e-05f, 4.671214992413297e-05f, 7.310106593649834e-05f, 6.931274401722476e-05f, 3.324385397718288e-05f, 3.864613609039225e-05f, 4.03006088163238e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0016752438386902213f, 0.0011007881257683039f, 0.0021212222054600716f, 0.0016720900312066078f, 0.0033839107491075993f, 0.005466890521347523f, 0.0009913442190736532f, 0.00433716643601656f, 0.0012914149556308985f, 0.0009038459975272417f, 0.0046142577193677425f, 0.0034383339807391167f, 0.0019203113624826074f, 0.0015857855323702097f, 0.002548594493418932f, 0.003320808755233884f, 0.0034600121434777975f, 0.0025820129085332155f, 0.005019256379455328f, 0.0015606784727424383f, 0.002656141296029091f, 0.0039764270186424255f, 0.002727180253714323f, 0.003381117945536971f, 0.0011720096226781607f, 0.0023478278890252113f, 0.003787610214203596f, 0.002029997296631336f, 0.0022876313887536526f, 0.00213614315725863f, 0.0023634317331016064f, 0.0017935459036380053f, 0.004293633624911308f, 0.004335134755820036f, 0.0022950521670281887f, 0.004010678268969059f, 0.004013176076114178f, 0.002561375265941024f, 0.001925574615597725f, 0.0027711973525583744f, 0.0016275877133011818f, 0.0014552100328728557f, 0.003864248748868704f, 0.0030126883648335934f, 0.00145988748408854f, 0.0015100775053724647f, 0.0010004575597122312f, 0.0010236911475658417f, 0.0038882324006408453f, 0.002639114623889327f, 0.0018644069787114859f, 0.0011363490484654903f, 0.002735857618972659f, 0.0035113217309117317f, 0.0025297210086137056f, 0.0028840575832873583f, 0.0016282093711197376f, 0.0017627134220674634f, 0.0027070590294897556f, 0.0026219943538308144f, 0.0038150548934936523f, 0.002871572505682707f, 0.0009396154782734811f, 0.0019571941811591387f, 0.0015384528087452054f, 0.002891086507588625f, 0.002416693139821291f, 0.00363555527292192f, 0.0023225806653499603f, 0.0032083617988973856f, 0.0037874230183660984f, 0.002728880848735571f, 0.0034001285675913095f, 0.0030097118578851223f, 0.0034780262503772974f, 0.0009478511638008058f, 0.002470731269568205f, 0.00223160395398736f, 0.0018580058822408319f, 0.002367537934333086f, 0.0015200653579086065f, 0.0025773176457732916f, 0.0022187456488609314f, 0.0023388080298900604f, 0.002557925181463361f, 0.003198994556441903f, 0.0027720467187464237f, 0.0018815629882737994f, 0.0009548916132189333f, 0.003006936749443412f, 0.002215675078332424f, 0.003867567516863346f, 0.0050782994367182255f, 0.0030319388024508953f, 0.0015203652437776327f, 0.003368973731994629f, 0.0026774867437779903f, 0.0022956032771617174f, 0.002293777884915471f, 0.0029031923040747643f, 0.0020160756539553404f, 0.0012941083405166864f, 0.003071698360145092f, 0.003808570560067892f, 0.003304180921986699f, 0.0035669670905917883f, 0.0013581345556303859f, 0.0020864957477897406f, 0.003674751613289118f, 0.0025778019335120916f, 0.001241696416400373f, 0.002768565434962511f, 0.0044646114110946655f, 0.0016616496723145247f, 0.0010001289192587137f, 0.0009581615449860692f, 0.0017500428948551416f, 0.001414351281709969f, 0.0028668034356087446f, 0.00317397341132164f, 0.0011868597939610481f, 0.0022931713610887527f, 0.00227622059173882f, 0.003562117228284478f, 0.0033775174524635077f, 0.001619928516447544f, 0.0018831745255738497f, 0.0019637946970760822f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.413930481765419e-05f, 0.0001636223023524508f, 0.00014311145059764385f, 0.00010780207958305255f, 0.00018871687643695623f, 9.223337838193402e-05f, 0.00019869404786732048f, 0.00010098773782374337f, 0.00018822858692146838f, 0.00016218102246057242f, 0.00016689182666596025f, 9.71342233242467e-05f, 0.00014599393762182444f, 0.00015476484259124845f, 0.00022812436509411782f, 0.00011419710062909871f, 0.0001529635046608746f, 3.371247657923959e-05f, 0.00017157754336949438f, 6.869883509352803e-05f, 6.995679723331705e-05f, 8.297157182823867e-05f, 0.00014158105477690697f, 8.604134200140834e-05f, 0.00025311674107797444f, 0.00024200321058742702f, 0.00012148958921898156f, 0.00016310637874994427f, 0.00017807351832743734f, 0.00021151920373085886f, 0.00010256304813083261f, 8.277637243736535e-05f, 0.00012092009274056181f, 0.00013161535025574267f, 0.0001460590137867257f, 7.071677828207612e-05f, 7.95737505541183e-05f, 0.0002346617984585464f, 0.00016468102694489062f, 0.00015846927999518812f, 0.00020444679830688983f, 6.98507355991751e-05f, 0.00011043374252039939f, 6.51749869575724e-05f, 0.00013010155817028135f, 0.0001422875066054985f, 0.00014564167940989137f, 0.00013558506907429546f, 0.0001862737408373505f, 4.7138717491179705e-05f, 8.350310235982761e-05f, 4.2710478737717494e-05f, 0.0001606134173925966f, 0.00030000542756170034f, 0.0003239662910345942f, 0.00015120203897822648f, 0.0001977607316803187f, 0.00011642117169685662f, 0.00017673935508355498f, 4.4555406930157915e-05f, 0.00016356175183318555f, 0.0001445926318410784f, 0.0003041715535800904f, 9.467218478675932e-05f, 0.0002554226666688919f, 8.403198444284499e-05f, 0.00014344108058139682f, 0.00010597179061733186f, 4.855869337916374e-05f, 8.320409688167274e-05f, 0.00011316017480567098f, 0.00014035492495168f, 4.599417297868058e-05f, 0.00014699986786581576f, 0.00016360868175979704f, 0.00037732443888671696f, 9.947270154953003e-05f, 0.000119322125101462f, 0.00016301502182614058f, 6.473197572631761e-05f, 0.00017772710998542607f, 0.0001886246318463236f, 9.209699783241376e-05f, 0.00015703162353020161f, 7.286910113180056e-05f, 0.00031173357274383307f, 0.0001900429924717173f, 0.00010687510803109035f, 0.00021559902234002948f, 0.00012150734983151779f, 0.0001452754659112543f, 9.286699787480757e-05f, 0.00015274407633114606f, 0.00010961763473460451f, 0.00014514441136270761f, 7.605739665450528e-05f, 0.00014867361460346729f, 0.00015263089153449982f, 0.00017330113041680306f, 0.00011306117085041478f, 0.0001341719616902992f, 0.0001325873745372519f, 7.479992200387642e-05f, 0.00011698068556142971f, 0.00023831173893995583f, 0.0001564287522342056f, 0.00021354120690375566f, 0.000278893654467538f, 0.00013152931933291256f, 0.00016444675566162914f, 7.192305929493159e-05f, 0.00013694315566681325f, 6.004597889841534e-05f, 4.064398308400996e-05f, 0.0002240076137240976f, 0.00012066557974321768f, 0.00016629527090117335f, 8.138380508171394e-05f, 0.0002922459680121392f, 0.0001635193038964644f, 4.556772546493448e-05f, 6.0207654314581305e-05f, 0.00020572353969328105f, 0.00013194982602726668f, 0.0002046876325039193f, 0.00039090137579478323f, 0.0003179383638780564f, 8.176872506737709e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004487586673349142f, 0.00872682873159647f, 0.007632877677679062f, 0.00574964564293623f, 0.010065252892673016f, 0.004919285885989666f, 0.010597387328743935f, 0.005386201199144125f, 0.010039209388196468f, 0.008649957366287708f, 0.008901209570467472f, 0.005180673208087683f, 0.007786616217344999f, 0.008254414424300194f, 0.012167058885097504f, 0.006090725306421518f, 0.008158339187502861f, 0.0017980617703869939f, 0.009151122532784939f, 0.003664066083729267f, 0.0037311597261577845f, 0.0044253054074943066f, 0.007551254238933325f, 0.004589032381772995f, 0.013500032015144825f, 0.012907289899885654f, 0.006479671690613031f, 0.008699311874806881f, 0.009497586637735367f, 0.011281419545412064f, 0.005470220930874348f, 0.0044148946180939674f, 0.006449297536164522f, 0.007019731216132641f, 0.007790086790919304f, 0.003771693678572774f, 0.0042440821416676044f, 0.012515733949840069f, 0.008783295750617981f, 0.008451990783214569f, 0.010904211550951004f, 0.0037255031056702137f, 0.005890005733817816f, 0.0034761212300509214f, 0.0069389925338327885f, 0.007588932756334543f, 0.007767828181385994f, 0.007231457158923149f, 0.009934947825968266f, 0.0025141530204564333f, 0.004453654866665602f, 0.0022779719438403845f, 0.008566348813474178f, 0.01600085012614727f, 0.01727880723774433f, 0.00806439109146595f, 0.010547608137130737f, 0.00620934646576643f, 0.009426428936421871f, 0.002376371528953314f, 0.008723598904907703f, 0.00771187711507082f, 0.01622305065393448f, 0.005049359984695911f, 0.013623019680380821f, 0.004481862764805555f, 0.007650458719581366f, 0.005652026738971472f, 0.0025898877065628767f, 0.004437707364559174f, 0.006035420577973127f, 0.007485858164727688f, 0.002453108550980687f, 0.00784026738256216f, 0.00872610229998827f, 0.02012467570602894f, 0.005305396392941475f, 0.006364069413393736f, 0.008694439195096493f, 0.003452492877840996f, 0.009479111060500145f, 0.010060332715511322f, 0.004912011791020632f, 0.008375313133001328f, 0.003886488266289234f, 0.016626372933387756f, 0.010135981254279613f, 0.005700205452740192f, 0.011499017477035522f, 0.006480618845671415f, 0.007748296484351158f, 0.004953079856932163f, 0.008146636188030243f, 0.005846478510648012f, 0.007741306442767382f, 0.004056536592543125f, 0.007929537445306778f, 0.008140599355101585f, 0.009243050590157509f, 0.006030140444636345f, 0.007156088948249817f, 0.007071574218571186f, 0.003989468794316053f, 0.006239188369363546f, 0.012710404582321644f, 0.008343159221112728f, 0.011389262974262238f, 0.014874848537147045f, 0.00701514258980751f, 0.00877080112695694f, 0.003836030839011073f, 0.007303890772163868f, 0.0032025643158704042f, 0.002167755039408803f, 0.011947491206228733f, 0.006435723043978214f, 0.008869391866028309f, 0.004340621642768383f, 0.015586997382342815f, 0.008721334859728813f, 0.002430363791063428f, 0.003211187431588769f, 0.01097230613231659f, 0.007037570234388113f, 0.0109170563519001f, 0.020848803222179413f, 0.01695730723440647f, 0.004361151251941919f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.134217205224559e-05f, 0.00010350798402214423f, 5.3234580263961107e-05f, 4.559219451039098e-05f, 4.616460864781402e-05f, 0.00012724257248919457f, 6.512408435810357e-05f, 5.7185126934200525e-05f, 7.319977157749236e-05f, 5.648436490446329e-05f, 5.4853386245667934e-05f, 3.751150507014245e-05f, 8.946032903622836e-05f, 4.433036156115122e-05f, 5.2371509809745476e-05f, 5.014344060327858e-05f, 8.369646093342453e-05f, 7.997943612281233e-05f, 0.00011302473285468295f, 5.307350147631951e-05f, 3.187474067090079e-05f, 5.421089372248389e-05f, 6.05326822551433e-05f, 5.373229942051694e-05f, 2.8032676709699444e-05f, 2.380220939812716e-05f, 7.388296944554895e-05f, 8.553856605431065e-05f, 3.2056930649559945e-05f, 3.1740164558868855e-05f, 7.971525337779894e-05f, 3.683605245896615e-05f, 3.947090954170562e-05f, 4.5857930672354996e-05f, 8.960442937677726e-05f, 6.584420043509454e-05f, 7.274946983670816e-05f, 3.313862544018775e-05f, 5.324286030372605e-05f, 8.328848343808204e-05f, 0.00010362499597249553f, 7.122890383470803e-05f, 0.0001068326600943692f, 8.204506593756378e-05f, 2.5114111849688925e-05f, 5.40859364264179e-05f, 6.0738675529137254e-05f, 7.505337271140888e-05f, 4.78901929454878e-05f, 0.00010150185698876157f, 4.8290836275555193e-05f, 7.61081391829066e-05f, 0.00010069972631754354f, 2.5880674002110027e-05f, 3.3101081498898566e-05f, 0.00011019947123713791f, 3.6478228139458224e-05f, 5.5319269449682906e-05f, 6.6699183662422e-05f, 7.939493661979213e-05f, 5.110682104714215e-05f, 5.434999548015185e-05f, 2.9413122319965623e-05f, 7.402523624477908e-05f, 3.171339267282747e-05f, 6.759131792932749e-05f, 9.717254579300061e-05f, 4.22845441789832e-05f, 5.3018175094621256e-05f, 9.181289351545274e-05f, 7.060245843604207e-05f, 3.75131203327328e-05f, 6.315958307823166e-05f, 0.0001034750384860672f, 9.833881631493568e-05f, 1.569911364640575e-05f, 4.976420314051211e-05f, 3.698119689943269e-05f, 3.8613103242823854e-05f, 6.616360769839957e-05f, 3.3166266803164035e-05f, 4.19398165831808e-05f, 4.190793333691545e-05f, 5.929690451011993e-05f, 3.865511462208815e-05f, 3.13588825520128e-05f, 7.010663830442354e-05f, 6.631920405197889e-05f, 8.290959522128105e-05f, 7.817232108209282e-05f, 7.708716293564066e-05f, 7.843164348741993e-05f, 3.637942427303642e-05f, 0.00012132751726312563f, 6.458310963353142e-05f, 6.919301813468337e-05f, 7.390803511952981e-05f, 2.7492309527588077e-05f, 5.780531500931829e-05f, 4.3609186832327396e-05f, 6.538847082993016e-05f, 8.75225305208005e-05f, 7.487697439501062e-05f, 7.058379560476169e-05f, 4.470710700843483e-05f, 7.800118328304961e-05f, 2.3183807570603676e-05f, 2.1786663637612946e-05f, 8.693785639479756e-05f, 4.4717962737195194e-05f, 8.173399692168459e-05f, 4.5072778448229656e-05f, 4.478144910535775e-05f, 4.8970636271405965e-05f, 2.6939724193653092e-05f, 0.00011225562775507569f, 6.823670264566317e-05f, 5.840610174345784e-05f, 4.6967645175755024e-05f, 6.026513074175455e-05f, 6.45904874545522e-05f, 6.144641520222649e-05f, 5.7812954764813185e-05f, 3.8031219446565956e-05f, 7.21188698662445e-05f, 8.074453216977417e-05f, 3.1881492759566754e-05f, 5.9431597037473693e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004412057343870401f, 0.005614346358925104f, 0.0028874813579022884f, 0.00247295293956995f, 0.0025040011387318373f, 0.006901727523654699f, 0.0035323763731867075f, 0.003101761918514967f, 0.003970407415181398f, 0.003063752083107829f, 0.0029752866830676794f, 0.0020346506498754025f, 0.00485239177942276f, 0.0024045102763921022f, 0.002840667963027954f, 0.002719815820455551f, 0.004539755638688803f, 0.004338141530752182f, 0.006130541674792767f, 0.002878744387999177f, 0.0017289086245000362f, 0.002940437290817499f, 0.003283335594460368f, 0.0029144780710339546f, 0.0015205122763291001f, 0.001291048713028431f, 0.004007464740425348f, 0.004639672581106424f, 0.0017387906555086374f, 0.001721609034575522f, 0.004323811735957861f, 0.001998013583943248f, 0.0021409301552921534f, 0.00248736678622663f, 0.00486020790413022f, 0.0035714362747967243f, 0.00394598301500082f, 0.0017974625807255507f, 0.0028879304882138968f, 0.004517626482993364f, 0.005620693322271109f, 0.0038635062519460917f, 0.005794679280370474f, 0.004450182430446148f, 0.0013622072292491794f, 0.002933659590780735f, 0.0032945089042186737f, 0.004070948343724012f, 0.0025975981261581182f, 0.005505532957613468f, 0.0026193291414529085f, 0.004128159489482641f, 0.005462024826556444f, 0.0014037861255928874f, 0.001795426127500832f, 0.00597729766741395f, 0.001978605054318905f, 0.003000556491315365f, 0.0036178110167384148f, 0.004306437913328409f, 0.0027720702346414328f, 0.0029479824006557465f, 0.0015953886322677135f, 0.004015181213617325f, 0.0017201568698510528f, 0.0036662009079009295f, 0.0052707078866660595f, 0.0022935436572879553f, 0.0028757434338331223f, 0.0049799964763224125f, 0.003829527646303177f, 0.0020347381941974163f, 0.0034258204977959394f, 0.005612559616565704f, 0.005333967041224241f, 0.000851531105581671f, 0.002699245698750019f, 0.002005886286497116f, 0.0020944022107869387f, 0.003588760970160365f, 0.001798961777240038f, 0.0022748454939574003f, 0.0022731160279363394f, 0.0032163062132894993f, 0.002096680924296379f, 0.0017009280854836106f, 0.0038026338443160057f, 0.0035972008481621742f, 0.004497075453400612f, 0.004240122158080339f, 0.004181262571364641f, 0.004254187922924757f, 0.00197324575856328f, 0.0065808906219899654f, 0.0035030338913202286f, 0.0037530784029513597f, 0.004008824471384287f, 0.0014912023907527328f, 0.003135401289910078f, 0.0023653933312743902f, 0.0035467168781906366f, 0.004747284110635519f, 0.0040613804012537f, 0.003828515065833926f, 0.0024249451234936714f, 0.004230839665979147f, 0.0012575061991810799f, 0.001181724132038653f, 0.004715571179986f, 0.002425533952191472f, 0.004433310125023127f, 0.0024447795003652573f, 0.002428977517411113f, 0.0026562020648270845f, 0.0014612297527492046f, 0.0060888249427080154f, 0.0037012072280049324f, 0.0031679884996265173f, 0.0025475583970546722f, 0.003268823493272066f, 0.003503433894366026f, 0.0033328973222523928f, 0.003135815728455782f, 0.002062840387225151f, 0.003911778796464205f, 0.00437964079901576f, 0.001729274750687182f, 0.0032236119732260704f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018185672524850816f, 0.0002967912005260587f, 0.00017518532695248723f, 9.903169120661914e-05f, 4.5216158468974754e-05f, 6.440074503188953e-05f, 0.00014033372281119227f, 0.0001686079049250111f, 0.00011066634760936722f, 7.178126543294638e-05f, 0.0004201490373816341f, 0.00020022736862301826f, 0.00017447611026000232f, 0.00014086625014897436f, 0.00028895813738927245f, 0.00037308086757548153f, 0.00019622176478151232f, 7.418034510919824e-05f, 0.00018274957255925983f, 7.807777001289651e-05f, 0.0002510833437554538f, 0.00021484265744220465f, 0.0002980453718919307f, 0.00020163229783065617f, 0.000135010079247877f, 0.00015739205991849303f, 5.773788143415004e-05f, 0.00017605216999072582f, 0.00017036625649780035f, 0.0001995760976569727f, 0.00017969869077205658f, 0.00023142465215642005f, 0.00027098561986349523f, 0.0002931935014203191f, 0.00012965762289240956f, 5.583934762398712e-05f, 0.00025806264602579176f, 0.00024641744676046073f, 0.00015042202721815556f, 0.00026013512979261577f, 0.0002765393001027405f, 0.00017998862313106656f, 0.00020060670794919133f, 7.495067256968468e-05f, 0.00027136135031469166f, 0.00029743005870841444f, 0.0002785446704365313f, 0.0001165749054052867f, 5.368125130189583e-05f, 0.00025678699603304267f, 0.00012529679224826396f, 0.00013917754404246807f, 0.00011901082325493917f, 0.00014224814367480576f, 0.00013564869004767388f, 0.00018949199875351042f, 0.00012615199375431985f, 0.0002340194769203663f, 5.7186691265087575e-05f, 6.559382018167526e-05f, 4.99504640174564e-05f, 0.00022607481514569372f, 0.00021931347146164626f, 0.0001849137042881921f, 0.00016248282918240875f, 4.295760300010443e-05f, 0.0003863860620185733f, 0.0001775026903487742f, 0.00027613178826868534f, 0.00028550653951242566f, 9.468904318055138e-05f, 0.00020353577565401793f, 0.0001507092674728483f, 0.00016428690287284553f, 0.0002625045017339289f, 0.0001874302251962945f, 0.0003701274690683931f, 0.0001815427967812866f, 0.00025720804114826024f, 0.0003904233162757009f, 0.00013168953591957688f, 9.267325367545709e-05f, 8.063043787842616e-05f, 0.00015240165521390736f, 0.00022010548855178058f, 5.8276764320908114e-05f, 0.0001033482767525129f, 9.197158215101808e-05f, 0.00017447341815568507f, 0.00011872543836943805f, 0.00024354011111427099f, 9.080314339371398e-05f, 0.0002809049910865724f, 0.0002902046253439039f, 0.00041382043855264783f, 0.000380836077965796f, 0.00011822537635453045f, 0.00041450647404417396f, 0.00011723316856659949f, 0.00018422243010718375f, 0.00028604781255126f, 0.00021760199160780758f, 0.00014744745567440987f, 0.00010454202856635675f, 0.0002801779191941023f, 0.0001578639494255185f, 0.00020795868476852775f, 0.00018510338850319386f, 0.00010405690409243107f, 0.00011195728438906372f, 0.00011187905329279602f, 0.00019097773474641144f, 0.00013797312567476183f, 0.00022857257863506675f, 0.000262296583969146f, 0.00014890532474964857f, 0.0002590460062492639f, 0.000436796952271834f, 0.0002730630221776664f, 0.0001282592274947092f, 0.0003048551152460277f, 0.0002966913452837616f, 0.00016958329069893807f, 0.0002006934373639524f, 0.0003153776633553207f, 0.00022594571055378765f, 0.0002939052355941385f, 0.0002739486226346344f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00977100059390068f, 0.01594632863998413f, 0.0094125522300601f, 0.005320884753018618f, 0.002429424086585641f, 0.003460194915533066f, 0.007540006656199694f, 0.009059153497219086f, 0.005946004763245583f, 0.003856743685901165f, 0.022574234753847122f, 0.010758038610219955f, 0.009374446235597134f, 0.00756861874833703f, 0.015525463968515396f, 0.02004530467092991f, 0.010542821139097214f, 0.003985644318163395f, 0.00981897208839655f, 0.004195049405097961f, 0.013490485027432442f, 0.011543305590748787f, 0.01601371355354786f, 0.01083352416753769f, 0.007253971882164478f, 0.008456535637378693f, 0.003102205228060484f, 0.009459126740694046f, 0.009153627790510654f, 0.010723046958446503f, 0.009655050933361053f, 0.012434241361916065f, 0.014559817500412464f, 0.01575302705168724f, 0.006966389250010252f, 0.003000198630616069f, 0.013865477405488491f, 0.013239790685474873f, 0.008082042448222637f, 0.013976830057799816f, 0.01485821045935154f, 0.009670629166066647f, 0.010778420604765415f, 0.004027033224701881f, 0.01458000484853983f, 0.01598065346479416f, 0.014965957961976528f, 0.006263466086238623f, 0.0028842459432780743f, 0.01379693765193224f, 0.006732085254043341f, 0.007477885577827692f, 0.0063943457789719105f, 0.0076428665779531f, 0.007288284134119749f, 0.010181237012147903f, 0.006778034381568432f, 0.012573658488690853f, 0.0030725901015102863f, 0.0035242976155132055f, 0.0026837941259145737f, 0.012146798893809319f, 0.011783517897129059f, 0.009935249574482441f, 0.008730058558285236f, 0.0023080739192664623f, 0.020760180428624153f, 0.009537061676383018f, 0.014836315996944904f, 0.01534001249819994f, 0.005087558180093765f, 0.010935796424746513f, 0.00809747539460659f, 0.00882698968052864f, 0.014104134403169155f, 0.01007045991718769f, 0.019886620342731476f, 0.00975413341075182f, 0.013819560408592224f, 0.020977098494768143f, 0.0070755621418356895f, 0.004979251883924007f, 0.004332202021032572f, 0.008188406005501747f, 0.011826072819530964f, 0.003131158882752061f, 0.005552811082452536f, 0.0049415514804422855f, 0.009374301880598068f, 0.006379012484103441f, 0.013085193932056427f, 0.004878772422671318f, 0.015092776156961918f, 0.015592437237501144f, 0.022234205156564713f, 0.02046198397874832f, 0.006352144759148359f, 0.022271065041422844f, 0.00629883399233222f, 0.009898107498884201f, 0.015369095839560032f, 0.01169156190007925f, 0.007922220975160599f, 0.005616950336843729f, 0.015053710900247097f, 0.008481889963150024f, 0.011173435486853123f, 0.009945441037416458f, 0.005590884946286678f, 0.006015365477651358f, 0.006011162418872118f, 0.010261064395308495f, 0.00741317356005311f, 0.012281001545488834f, 0.014092962257564068f, 0.008000550791621208f, 0.013918311335146427f, 0.023468712344765663f, 0.01467143464833498f, 0.006891254801303148f, 0.016379594802856445f, 0.015940962359309196f, 0.009111559949815273f, 0.010783080011606216f, 0.01694496162235737f, 0.012139862403273582f, 0.015791267156600952f, 0.014719015918672085f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.574831862351857e-05f, 4.2556202970445156e-05f, 8.857232023729011e-05f, 7.789590745233e-05f, 5.792643059976399e-05f, 9.987015801016241e-05f, 4.645221997634508e-05f, 3.753504643100314e-05f, 4.336561687523499e-05f, 4.20003998442553e-05f, 4.103599349036813e-05f, 4.9614762247074395e-05f, 7.801388710504398e-05f, 6.588986434508115e-05f, 3.564476719475351e-05f, 1.814029565139208e-05f, 4.410983819980174e-05f, 7.63321659178473e-05f, 3.320200994494371e-05f, 0.00010219296382274479f, 3.349528560647741e-05f, 3.630966602941044e-05f, 2.7711077564163134e-05f, 7.765240297885612e-05f, 2.0572913854266517e-05f, 3.361791459610686e-05f, 7.18228766345419e-05f, 5.0313967221882194e-05f, 4.563953189062886e-05f, 2.843034963007085e-05f, 4.493672531680204e-05f, 2.8780235879821703e-05f, 3.3384534617653117e-05f, 3.750757605303079e-05f, 9.430761565454304e-05f, 5.8753495977725834e-05f, 4.497847839957103e-05f, 2.991928340634331e-05f, 3.2447136618429795e-05f, 3.147207826259546e-05f, 3.207511326763779e-05f, 4.7761979658389464e-05f, 4.2367530113551766e-05f, 7.851752889109775e-05f, 3.812693103100173e-05f, 4.099947545910254e-05f, 2.370923903072253e-05f, 9.485107875661924e-05f, 5.746007082052529e-05f, 3.8663161831209436e-05f, 0.00010039786866400391f, 4.853978316532448e-05f, 6.513570406241342e-05f, 7.120597729226574e-05f, 4.3827858462464064e-05f, 3.570141052477993e-05f, 3.875662150676362e-05f, 4.7922843805281445e-05f, 5.334784873411991e-05f, 6.845593452453613e-05f, 0.00010350047523388639f, 2.6668527425499633e-05f, 3.320150062791072e-05f, 5.279203469399363e-05f, 6.526585639221594e-05f, 0.00010023749200627208f, 5.8094170526601374e-05f, 4.224041913403198e-05f, 2.8356511393212713e-05f, 4.1116203647106886e-05f, 0.00010708357876865193f, 3.8942274841247126e-05f, 4.627644011634402e-05f, 6.40807265881449e-05f, 1.983177753572818e-05f, 4.319643630879e-05f, 3.900888259522617e-05f, 4.767622158396989e-05f, 2.9540191462729126e-05f, 8.607665222370997e-05f, 8.96562632988207e-05f, 6.203924567671493e-05f, 7.180988905020058e-05f, 8.75550031196326e-05f, 4.728361454908736e-05f, 6.883308378746733e-05f, 3.1018807931104675e-05f, 0.00013606117863673717f, 8.271728438558057e-05f, 0.00010834626300493255f, 2.225419484602753e-05f, 6.812717037973925e-05f, 4.056644320371561e-05f, 4.649444599635899e-05f, 2.4196209778892808e-05f, 4.091492519364692e-05f, 5.1399500080151483e-05f, 3.5996366932522506e-05f, 5.412275640992448e-05f, 4.548545621219091e-05f, 3.102274058619514e-05f, 5.510851406143047e-05f, 5.1540522690629587e-05f, 8.670904207974672e-05f, 2.1971211026539095e-05f, 7.381448085652664e-05f, 4.174971400061622e-05f, 4.340564555604942e-05f, 4.5248041715240106e-05f, 6.687608401989564e-05f, 0.0001283691090065986f, 3.469966395641677e-05f, 5.6623608543304726e-05f, 3.012494562426582e-05f, 2.608535396575462e-05f, 3.362546704011038e-05f, 4.939953942084685e-05f, 3.0758372304262593e-05f, 2.5994773750426248e-05f, 6.58584976918064e-05f, 1.9146358681609854e-05f, 3.512813782435842e-05f, 7.942173397168517e-05f, 6.832191138528287e-05f, 2.803221832436975e-05f, 5.711856283596717e-05f, 1.8780207028612494e-05f, 3.7099973269505426e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002133158501237631f, 0.002539395820349455f, 0.005285250023007393f, 0.004648171830922365f, 0.003456561593338847f, 0.0059594097547233105f, 0.0027718772180378437f, 0.002239775378257036f, 0.002587694674730301f, 0.0025062300264835358f, 0.002448682440444827f, 0.002960591111332178f, 0.004655211698263884f, 0.003931751940399408f, 0.002126979408785701f, 0.0010824600467458367f, 0.0026321036275476217f, 0.004554860759526491f, 0.001981216249987483f, 0.006098015233874321f, 0.001998716499656439f, 0.002166655147448182f, 0.0016535636968910694f, 0.0046336413361132145f, 0.00122761819511652f, 0.0020060339011251926f, 0.004285784438252449f, 0.0030023138970136642f, 0.0027233827859163284f, 0.0016964838141575456f, 0.0026814453303813934f, 0.0017173620872199535f, 0.0019921078346669674f, 0.002238136250525713f, 0.005627484060823917f, 0.0035059137735515833f, 0.0026839368510991335f, 0.001785330823622644f, 0.0019361719023436308f, 0.0018779885722324252f, 0.0019139726646244526f, 0.0028500326443463564f, 0.002528137294575572f, 0.004685265012085438f, 0.0022750941570848227f, 0.0024465033784508705f, 0.001414767699316144f, 0.005659913644194603f, 0.0034287329763174057f, 0.0023070918396115303f, 0.005990899167954922f, 0.0028964453376829624f, 0.0038867504335939884f, 0.004248972982168198f, 0.002615277422592044f, 0.002130359411239624f, 0.0023126688320189714f, 0.002859631786122918f, 0.0031833501998335123f, 0.004084873478859663f, 0.006176036782562733f, 0.0015913530951365829f, 0.001981185982003808f, 0.003150183940306306f, 0.0038945164997130632f, 0.00598132936283946f, 0.0034665707498788834f, 0.00252055237069726f, 0.0016920777270570397f, 0.0024534687399864197f, 0.006389846093952656f, 0.0023237469140440226f, 0.002761388197541237f, 0.0038237981498241425f, 0.0011833934113383293f, 0.0025775996036827564f, 0.0023277215659618378f, 0.002844915259629488f, 0.0017627098131924868f, 0.005136329680681229f, 0.005349930841475725f, 0.003701979760080576f, 0.004285009577870369f, 0.005224545020610094f, 0.0028214878402650356f, 0.004107378888875246f, 0.0018509411020204425f, 0.00811898522078991f, 0.004935870878398418f, 0.0064651924185454845f, 0.0013279429404065013f, 0.004065255634486675f, 0.0024206636007875204f, 0.002774396911263466f, 0.0014438260113820434f, 0.002441458171233535f, 0.00306708924472332f, 0.0021479600109159946f, 0.003229590365663171f, 0.002714189002290368f, 0.0018511759117245674f, 0.0032884120009839535f, 0.003075504209846258f, 0.005174065474420786f, 0.0013110567815601826f, 0.0044046263210475445f, 0.0024912713561207056f, 0.002590083284303546f, 0.002700021956115961f, 0.003990601282566786f, 0.007659987546503544f, 0.002070583635941148f, 0.003378820139914751f, 0.001797602977603674f, 0.0015565542271360755f, 0.0020064846612513065f, 0.0029477484058588743f, 0.0018354005878791213f, 0.0015511491801589727f, 0.0039298804476857185f, 0.001142493449151516f, 0.00209615146741271f, 0.004739220254123211f, 0.00407687621191144f, 0.0016727267066016793f, 0.0034083547070622444f, 0.0011206446215510368f, 0.002213813830167055f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.497638580389321e-05f, 0.00011008379078703001f, 6.435650720959529e-05f, 5.5273812904488295e-05f, 0.0001296215777983889f, 5.114418672746979e-05f, 0.000135205831611529f, 5.786737892776728e-05f, 4.2348478018539026e-05f, 5.890353713766672e-05f, 7.869952969485894e-05f, 8.672033436596394e-05f, 4.8930745833786204e-05f, 4.759203511639498e-05f, 8.065108704613522e-05f, 5.013405461795628e-05f, 6.684441905235872e-05f, 0.00015401116979774088f, 0.00018515205010771751f, 5.795474135084078e-05f, 9.439230052521452e-05f, 4.4829728722106665e-05f, 5.736054663429968e-05f, 5.6944867537822574e-05f, 5.973886436549947e-05f, 5.8551435358822346e-05f, 4.961791273672134e-05f, 6.393981311703101e-05f, 9.341525583295152e-05f, 6.639525963691995e-05f, 9.838811820372939e-05f, 5.094937660032883e-05f, 9.097798465518281e-05f, 5.4471249313792214e-05f, 5.2467217756202444e-05f, 5.9156634961254895e-05f, 0.00010355226550018415f, 0.00011474584607640281f, 4.975004412699491e-05f, 4.085868567926809e-05f, 3.786490924539976e-05f, 7.395954889943823e-05f, 5.249340392765589e-05f, 7.394699059659615e-05f, 6.844967720098794e-05f, 5.2293085900601e-05f, 8.979031554190442e-05f, 4.886735405307263e-05f, 4.443961370270699e-05f, 5.306669117999263e-05f, 5.991472062305547e-05f, 8.207235077861696e-05f, 7.484701200155541e-05f, 5.6072189181577414e-05f, 4.8981168220052496e-05f, 5.846436761203222e-05f, 5.62315181014128e-05f, 5.07980803376995e-05f, 5.3923027735436335e-05f, 6.456246046582237e-05f, 4.8549845814704895e-05f, 4.8293084546457976e-05f, 4.327684291638434e-05f, 5.718820102629252e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0043003675527870655f, 0.006313998252153397f, 0.003691250691190362f, 0.0031703009735792875f, 0.007434613071382046f, 0.002933440962806344f, 0.00775490514934063f, 0.003319058334454894f, 0.002428951673209667f, 0.003378488589078188f, 0.004513913299888372f, 0.004973956849426031f, 0.002806486329063773f, 0.002729702740907669f, 0.004625847563147545f, 0.0028755036182701588f, 0.0038339481689035892f, 0.008833509869873524f, 0.010619635693728924f, 0.003324069082736969f, 0.005413992330431938f, 0.0025712670758366585f, 0.00328998826444149f, 0.0032661466393619776f, 0.0034263997804373503f, 0.0033582933247089386f, 0.0028458996675908566f, 0.003667350858449936f, 0.005357952788472176f, 0.003808185923844576f, 0.005643177777528763f, 0.002922267420217395f, 0.00521815987303853f, 0.0031242689583450556f, 0.0030093251261860132f, 0.003393005346879363f, 0.005939374212175608f, 0.006581396330147982f, 0.0028534780722111464f, 0.002343502826988697f, 0.002171790925785899f, 0.004242045804858208f, 0.0030108271166682243f, 0.004241325426846743f, 0.00392601964995265f, 0.002999337622895837f, 0.005150039680302143f, 0.0028028502129018307f, 0.0025488915853202343f, 0.003043708624318242f, 0.0034364862367510796f, 0.00470736576244235f, 0.004292947240173817f, 0.0032160929404199123f, 0.002809378318488598f, 0.0033532993402332067f, 0.0032252315431833267f, 0.0029135895892977715f, 0.003092824947088957f, 0.003703063353896141f, 0.0027846391312777996f, 0.0027699123602360487f, 0.0024821993429213762f, 0.0032801032066345215f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001056743785738945f, 0.00014520116383209825f, 5.001149111194536e-05f, 0.00023159197007771581f, 5.938134927419014e-05f, 0.00021540443412959576f, 4.5607226638821885e-05f, 8.376505138585344e-05f, 7.90778940427117e-05f, 9.732290345709771e-05f, 0.00014722479681950063f, 4.521252412814647e-05f, 8.635869016870856e-05f, 5.8705198171082884e-05f, 0.000139714204124175f, 9.041262092068791e-05f, 0.00010939987987512723f, 6.154777656774968e-05f, 3.482867396087386e-05f, 0.0001635459193494171f, 9.899297583615407e-05f, 9.836895333137363e-05f, 9.770808537723497e-05f, 6.635249155806378e-05f, 0.0001469365379307419f, 0.00015201454516500235f, 0.0001233119546668604f, 0.0001278890122193843f, 9.964004857465625e-05f, 5.413213875726797e-05f, 7.035821909084916e-05f, 9.572581620886922e-05f, 4.012060526292771e-05f, 9.385671728523448e-05f, 0.00010947874397970736f, 0.00013991900777909905f, 4.707713014795445e-05f, 6.654475873801857e-05f, 8.856853673933074e-05f, 9.088424121728167e-05f, 0.0001391954137943685f, 4.9702375690685585e-05f, 9.273695468436927e-05f, 9.083463373826817e-05f, 9.304915147367865e-05f, 0.00015534697740804404f, 8.506378071615472e-05f, 0.00010665773879736662f, 7.274085510289297e-05f, 7.034797454252839e-05f, 8.81070300238207e-05f, 9.650371066527441e-05f, 0.00011147922486998141f, 0.00011740470654331148f, 7.211303454823792e-05f, 8.653147961013019e-05f, 0.00011701488983817399f, 0.00010475083399796858f, 8.849107689457014e-05f, 5.743019937654026e-05f, 0.00012801235425285995f, 0.00012361837434582412f, 9.392076026415452e-05f, 9.96592643787153e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004491161089390516f, 0.006171049550175667f, 0.0021254883613437414f, 0.009842658415436745f, 0.00252370722591877f, 0.009154688566923141f, 0.0019383070757612586f, 0.00356001453474164f, 0.0033608104567974806f, 0.004136223345994949f, 0.006257053464651108f, 0.0019215322099626064f, 0.0036702442448586226f, 0.002494970802217722f, 0.005937853362411261f, 0.003842536360025406f, 0.0046494947746396065f, 0.00261578056961298f, 0.0014802186051383615f, 0.006950701586902142f, 0.004207201302051544f, 0.0041806804947555065f, 0.004152593668550253f, 0.002819980727508664f, 0.006244802847504616f, 0.006460617762058973f, 0.005240757949650288f, 0.005435282830148935f, 0.004234701860696077f, 0.0023006158880889416f, 0.0029902243986725807f, 0.004068347159773111f, 0.0017051256727427244f, 0.003988910466432571f, 0.004652846604585648f, 0.005946557968854904f, 0.00200077798217535f, 0.0028281521517783403f, 0.0037641627714037895f, 0.00386258028447628f, 0.005915805231779814f, 0.002112350892275572f, 0.003941320348531008f, 0.0038604717701673508f, 0.0039545889012515545f, 0.006602246314287186f, 0.0036152107641100883f, 0.004532953724265099f, 0.003091486170887947f, 0.0029897887725383043f, 0.0037445486523211002f, 0.004101407714188099f, 0.004737867042422295f, 0.004989699926227331f, 0.0030648040119558573f, 0.0036775877233594656f, 0.004973132628947496f, 0.004451910499483347f, 0.003760870546102524f, 0.002440783428028226f, 0.0054405247792601585f, 0.005253780633211136f, 0.003991632256656885f, 0.004235518630594015f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012803221761714667f, 0.00022905955847818404f, 0.00014271512918639928f, 0.00024220340128522366f, 0.00018234857998322695f, 3.7654150219168514e-05f, 0.00012214234448038042f, 0.0003391773789189756f, 0.00039375387132167816f, 0.00033249426633119583f, 0.00017675894196145236f, 0.00012153641728218645f, 0.00015810046170372516f, 0.00033758298377506435f, 6.735184433637187e-05f, 9.950380626833066e-05f, 0.0003952847036998719f, 0.0002335493772989139f, 0.00016372022219002247f, 0.00031428461079485714f, 0.0002313203876838088f, 0.0002645886270329356f, 8.272163540823385e-05f, 0.00017173300147987902f, 0.00021651737915817648f, 0.00014609008212573826f, 5.8975816500606015e-05f, 0.00013649254105985165f, 0.00010078920604428276f, 0.00017858714272733778f, 0.0001280557335121557f, 9.438996494282037e-05f, 2.2992398953647353e-05f, 0.00029030514997430146f, 0.00015543881454505026f, 0.0001450368290534243f, 0.0001813707931432873f, 0.00018302172247786075f, 0.00011423475370975211f, 0.0001247421168955043f, 0.00017909277812577784f, 4.9630561989033595e-05f, 7.8652570664417e-05f, 0.00039385241689160466f, 0.0002782168739940971f, 0.00022689395700581372f, 0.00015875835379119962f, 2.2702468413626775e-05f, 0.0002547798794694245f, 0.00019330611394252628f, 4.341585372458212e-05f, 7.801458559697494e-05f, 0.00020024162949994206f, 8.541345596313477e-05f, 0.00010192755871685222f, 0.00012855812383349985f, 0.00021570433455053717f, 0.000166137600899674f, 0.00010443558130646124f, 0.00011561954306671396f, 0.0001394433929817751f, 0.00016429860261268914f, 0.00015306167188100517f, 0.00023891276214271784f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010057236067950726f, 0.017993174493312836f, 0.011210613884031773f, 0.019025655463337898f, 0.014323915354907513f, 0.0029578234534710646f, 0.009594572708010674f, 0.026643192395567894f, 0.030930304899811745f, 0.026118217036128044f, 0.013884836807847023f, 0.0095469756051898f, 0.012419168837368488f, 0.026517948135733604f, 0.005290647968649864f, 0.007816261611878872f, 0.031050557270646095f, 0.01834586076438427f, 0.012860613875091076f, 0.024687806144356728f, 0.01817076839506626f, 0.02078406699001789f, 0.006497981958091259f, 0.013490037061274052f, 0.01700795628130436f, 0.011475724168121815f, 0.004632690921425819f, 0.010721814818680286f, 0.007917232811450958f, 0.014028445817530155f, 0.010059082880616188f, 0.007414557039737701f, 0.0018061078153550625f, 0.02280416153371334f, 0.012210089713335037f, 0.011392989195883274f, 0.0142471082508564f, 0.014376793056726456f, 0.008973412215709686f, 0.009798790328204632f, 0.014068164862692356f, 0.00389859895221889f, 0.006178346928209066f, 0.030938047915697098f, 0.021854598075151443f, 0.01782306097447872f, 0.012470847927033901f, 0.001783333020284772f, 0.020013567060232162f, 0.015184656716883183f, 0.003410418750718236f, 0.006128231529146433f, 0.015729457139968872f, 0.006709430832415819f, 0.008006652817130089f, 0.010098547674715519f, 0.01694408990442753f, 0.013050504960119724f, 0.008203663863241673f, 0.009082190692424774f, 0.010953611694276333f, 0.012906047515571117f, 0.012023359537124634f, 0.018767166882753372f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.0817306803073734e-05f, 2.3449283617082983e-05f, 2.438900264678523e-05f, 3.8293208490358666e-05f, 0.0001512678136350587f, 3.823658698820509e-05f, 0.00016477204917464405f, 3.226221087970771e-05f, 2.4797842343105003e-05f, 3.254367402405478e-05f, 8.543280273443088e-05f, 6.425454921554774e-05f, 9.241294173989445e-05f, 6.524641503347084e-05f, 9.547371155349538e-05f, 3.279231532360427e-05f, 3.0194949431461282e-05f, 6.892858073115349e-05f, 1.9599950974225067e-05f, 2.28398093895521e-05f, 6.355538789648563e-05f, 2.9291677492437884e-05f, 9.399068949278444e-05f, 8.042623085202649e-05f, 3.7791323848068714e-05f, 5.6650991609785706e-05f, 0.00011490631732158363f, 3.557119271135889e-05f, 0.00023097949451766908f, 0.00017850572476163507f, 5.1110313506796956e-05f, 4.825858195545152e-05f, 0.000152370790601708f, 3.075725180679001e-05f, 5.55935112060979e-05f, 0.00011925145372515544f, 4.492002335609868e-05f, 6.189891428221017e-05f, 7.733783422736451e-05f, 3.9467166061513126e-05f, 8.606093615526333e-05f, 9.378463437315077e-05f, 5.875160786672495e-05f, 3.102027767454274e-05f, 4.1764233174035326e-05f, 5.190447700442746e-05f, 6.989061512285843e-05f, 8.362625521840528e-05f, 0.00011750718113034964f, 9.076482092496008e-05f, 5.048024468123913e-05f, 9.479628351982683e-05f, 7.60678158258088e-05f, 7.394045678665861e-05f, 4.120402081753127e-05f, 3.808477413258515e-05f, 5.164715548744425e-05f, 6.796597881475464e-05f, 8.782018267083913e-05f, 8.737068856135011e-05f, 6.403424049494788e-05f, 4.0472179534845054e-05f, 3.3725482353474945e-05f, 5.396850610850379e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003125715535134077f, 0.0012051798403263092f, 0.001253476832062006f, 0.001968085765838623f, 0.007774434518069029f, 0.0019651756156235933f, 0.008468486368656158f, 0.0016581217059865594f, 0.0012744892155751586f, 0.0016725874738767743f, 0.004390832968056202f, 0.0033023732248693705f, 0.004749578423798084f, 0.003353350330144167f, 0.00490688718855381f, 0.001685366383753717f, 0.0015518744476139545f, 0.003542595775797963f, 0.0010073427110910416f, 0.0011738557368516922f, 0.003266439540311694f, 0.0015054505784064531f, 0.004830666817724705f, 0.004133519250899553f, 0.0019422912737354636f, 0.0029115870129317045f, 0.005905629135668278f, 0.0018281872617080808f, 0.01187122892588377f, 0.009174331091344357f, 0.002626823028549552f, 0.0024802577681839466f, 0.007831121794879436f, 0.001580773969180882f, 0.0028572375886142254f, 0.0061289481818675995f, 0.002308672061190009f, 0.003181304782629013f, 0.003974790684878826f, 0.002028421498835087f, 0.004423115868121386f, 0.004820076748728752f, 0.003019548486918211f, 0.0015942923491820693f, 0.0021464796736836433f, 0.00266763917170465f, 0.003592039691284299f, 0.004297985229641199f, 0.006039300933480263f, 0.004664872772991657f, 0.0025944404769688845f, 0.004872070625424385f, 0.003909518010914326f, 0.003800181904807687f, 0.0021176873706281185f, 0.0019573732279241085f, 0.0026544141583144665f, 0.0034931227564811707f, 0.004513532854616642f, 0.004490430932492018f, 0.0032910502050071955f, 0.002080074278637767f, 0.0017333267023786902f, 0.0027737203054130077f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.037626346573234e-05f, 8.12145444797352e-05f, 4.5507818867918104e-05f, 6.331197801046073e-05f, 7.361862662946805e-05f, 7.765056216157973e-05f, 7.551561429863796e-05f, 5.227640940574929e-05f, 4.0333492506761104e-05f, 6.839619163656607e-05f, 6.778987881261855e-05f, 6.686704728053883e-05f, 5.6038876209640875e-05f, 0.00011279027967248112f, 7.752868987154216e-05f, 0.00012700304796453565f, 0.00012043902097502723f, 7.696550892433152e-05f, 9.519457671558484e-05f, 8.686396904522553e-05f, 7.454950537066907e-05f, 6.987458618823439e-05f, 0.00010316292173229158f, 5.058832175564021e-05f, 6.792467320337892e-05f, 6.657587073277682e-05f, 4.519223512033932e-05f, 7.178873056545854e-05f, 5.000957753509283e-05f, 0.00023989047622308135f, 5.5817668908275664e-05f, 9.376829257234931e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003752618096768856f, 0.004330539144575596f, 0.0024265774991363287f, 0.0033759346697479486f, 0.003925507888197899f, 0.004140499979257584f, 0.004026659764349461f, 0.0027874938677996397f, 0.0021506710909307003f, 0.003647036384791136f, 0.003614706452935934f, 0.0035654990933835506f, 0.002988116815686226f, 0.0060142274014651775f, 0.004134001210331917f, 0.006772083230316639f, 0.006422074977308512f, 0.004103971179574728f, 0.005075985565781593f, 0.004631779156625271f, 0.00397514458745718f, 0.003725867485627532f, 0.005500875413417816f, 0.00269748130813241f, 0.0036218937020748854f, 0.0035499727819114923f, 0.002409749897196889f, 0.003827933920547366f, 0.002666621236130595f, 0.012791491113603115f, 0.002976321615278721f, 0.004999932833015919f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018372363410890102f, 5.436482388176955e-05f, 0.0001365454081678763f, 0.00019912993593607098f, 9.793264325708151e-05f, 0.00010445307998452336f, 6.411326467059553e-05f, 0.00012626993702724576f, 0.0001531472080387175f, 0.00010794813715619966f, 8.464528946205974e-05f, 0.00015488729695789516f, 0.00010107610432896763f, 0.00014492575428448617f, 0.0001953841419890523f, 9.849361231317744e-05f, 5.3174640925135463e-05f, 0.00011701543553499505f, 5.1042417908320203e-05f, 9.392190258949995e-05f, 0.00014592493243981153f, 0.00019083445658907294f, 3.573445792426355e-05f, 0.00016782543389126658f, 0.0001662815921008587f, 6.441908772103488e-05f, 0.00013781918096356094f, 0.00014316065062303096f, 0.00013800064334645867f, 2.9225593607407063e-05f, 0.000116439834528137f, 0.00018978338630404323f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007808254566043615f, 0.0023105049040168524f, 0.005803179927170277f, 0.00846302229911089f, 0.004162137396633625f, 0.004439255688339472f, 0.002724813763052225f, 0.005366472061723471f, 0.0065087564289569855f, 0.004587795585393906f, 0.0035974248312413692f, 0.006582709960639477f, 0.0042957342229783535f, 0.006159344222396612f, 0.008303825743496418f, 0.004185978323221207f, 0.0022599222138524055f, 0.004973155912011862f, 0.0021693026646971703f, 0.003991680685430765f, 0.006201809737831354f, 0.008110464550554752f, 0.0015187144745141268f, 0.007132580503821373f, 0.007066967431455851f, 0.002737811068072915f, 0.005857315380126238f, 0.006084327585995197f, 0.005865027196705341f, 0.0012420876882970333f, 0.004948692861944437f, 0.008065793663263321f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005337906186468899f, 0.00042732281144708395f, 0.00022697070380672812f, 0.00011478322994662449f, 0.00023619315470568836f, 0.0010696176905184984f, 0.0005200182204134762f, 0.000209026547963731f, 0.0001622620184207335f, 0.0005160085274837911f, 0.00023991349735297263f, 0.0002505413431208581f, 0.00021733104949817061f, 0.0003440204600337893f, 0.000530662015080452f, 0.00021662730432581156f, 0.0002581235603429377f, 0.00031624731491319835f, 0.0003586101811379194f, 0.0004095502372365445f, 0.0002510450140107423f, 0.000154541659867391f, 0.0005377476918511093f, 0.000178212154423818f, 0.00035415252204984426f, 0.00021564739290624857f, 0.00018361759430263191f, 0.00017753186693880707f, 0.0004566646821331233f, 0.0002894248173106462f, 0.0004143243713770062f, 0.00016829230298753828f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022686099633574486f, 0.018161218613386154f, 0.00964625459164381f, 0.004878287203609943f, 0.010038209147751331f, 0.04545874893665314f, 0.022100772708654404f, 0.008883628062903881f, 0.006896135397255421f, 0.021930363029241562f, 0.0101963235065341f, 0.010648006573319435f, 0.00923656951636076f, 0.014620869420468807f, 0.022553134709596634f, 0.009206660091876984f, 0.010970250703394413f, 0.01344051118940115f, 0.015240931883454323f, 0.017405884340405464f, 0.010669413022696972f, 0.006568020209670067f, 0.0228542760014534f, 0.007574016693979502f, 0.015051481314003468f, 0.009165014140307903f, 0.007803747896105051f, 0.0075451042503118515f, 0.019408248364925385f, 0.012300554662942886f, 0.01760878600180149f, 0.007152422796934843f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.6404365750495344e-05f, 5.89149676670786e-05f, 0.00014112643839325756f, 8.337238250533119e-05f, 0.00021876840037293732f, 3.5158689570380375e-05f, 5.530780981644057e-05f, 0.00012923571921419352f, 0.00013243351713754237f, 3.652043960755691e-05f, 6.628045957768336e-05f, 0.00015508059004787356f, 0.0004152895126026124f, 0.00011634995462372899f, 8.362982043763623e-05f, 0.00016559759387746453f, 0.00012272989260964096f, 4.631794581655413e-05f, 4.934350727126002e-05f, 4.8941954446490854e-05f, 0.0002268672687932849f, 0.00016527832485735416f, 7.42889242246747e-05f, 0.0001907354744616896f, 5.599207725026645e-05f, 0.00023335411970037967f, 0.00020182605658192188f, 0.00014642671158071607f, 0.00011267764784861356f, 0.00017927408043760806f, 5.771722862846218e-05f, 8.569312194595113e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0027951467782258987f, 0.0029195609968155622f, 0.0069935922510921955f, 0.004131560679525137f, 0.010841178707778454f, 0.0017423066310584545f, 0.002740806434303522f, 0.006404341198503971f, 0.0065628099255263805f, 0.0018097888678312302f, 0.0032845616806298494f, 0.007685096934437752f, 0.020579881966114044f, 0.005765780806541443f, 0.00414431793615222f, 0.00820627249777317f, 0.00608194200322032f, 0.0022953092120587826f, 0.002445242367684841f, 0.0024253432638943195f, 0.011242521926760674f, 0.008190451189875603f, 0.003681425005197525f, 0.009451992809772491f, 0.002774715656414628f, 0.01156398095190525f, 0.010001592338085175f, 0.007256249897181988f, 0.0055837975814938545f, 0.00888401735574007f, 0.002860206412151456f, 0.004246565978974104f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.393769869348034e-05f, 0.00012182162026874721f, 4.4576645450433716e-05f, 0.00010356221901020035f, 0.00010890145495068282f, 7.743496826151386e-05f, 4.6777557145105675e-05f, 5.374564716476016e-05f, 8.76669873832725e-05f, 6.890231452416629e-05f, 0.0001346252829534933f, 0.00013388016668614f, 7.556999480584636e-05f, 7.377954898402095e-05f, 6.2559760408476e-05f, 0.00010049853881355375f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003992352169007063f, 0.005177418701350689f, 0.0018945073243230581f, 0.0044013941660523415f, 0.004628311842679977f, 0.0032909861765801907f, 0.0019880461040884256f, 0.0022841899190098047f, 0.0037258469965308905f, 0.002928348258137703f, 0.005721574649214745f, 0.0056899068877100945f, 0.003211724804714322f, 0.0031356308609247208f, 0.0026587897446006536f, 0.004271187819540501f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002760466013569385f, 0.00016894645523279905f, 0.000723334844224155f, 0.0006787975435145199f, 0.000425984151661396f, 0.0002583456225693226f, 0.0005764646921306849f, 0.0004309888754505664f, 0.0002953849034383893f, 0.00023244033218361437f, 0.0003718881926033646f, 0.0003552242706064135f, 0.0009016702533699572f, 0.00040268662269227207f, 0.00046108177048154175f, 0.0005405255360528827f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011731980368494987f, 0.007180224172770977f, 0.030741730704903603f, 0.02884889394044876f, 0.018104325979948044f, 0.010979688726365566f, 0.024499747902154922f, 0.018317027017474174f, 0.012553858570754528f, 0.009878713637590408f, 0.01580524817109108f, 0.015097031369805336f, 0.038320984691381454f, 0.01711418107151985f, 0.019595975056290627f, 0.022972336038947105f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.919457129901275e-05f, 0.00026998910470865667f, 0.0004003790090791881f, 0.00010017586464527994f, 8.928482566261664e-05f, 0.0002499606052879244f, 0.0002819723158609122f, 0.00013315649994183332f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004313090816140175f, 0.01470413338392973f, 0.021805420517921448f, 0.0054557728581130505f, 0.004862625617533922f, 0.013613341376185417f, 0.015356761403381824f, 0.007251962553709745f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.849213291890919e-05f, 6.759804819012061e-05f, 6.0725866205757484e-05f, 5.8651694416766986e-05f, 0.00010715490498114377f, 3.21967490890529e-05f, 7.434495273628272e-06f, 2.8963342629140243e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0123654929921031f, 0.017237501218914986f, 0.015485094860196114f, 0.014956180937588215f, 0.027324499562382698f, 0.008210170082747936f, 0.0018957961583510041f, 0.007385652046650648f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_x0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018361443653702736f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020179392769932747f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018753910437226295f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019457083195447922f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01273035816848278f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017434878274798393f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016758397221565247f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018611883744597435f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018436336889863014f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01874934323132038f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020521802827715874f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016826912760734558f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021304316818714142f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018657566979527473f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018495796248316765f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021298347041010857f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.014746660366654396f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.014464165084064007f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015806227922439575f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021198580041527748f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012925205752253532f),
    AI_PACK_INTQ_ZP(-17)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_33_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 9473, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9473, 9473),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3072, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3072, 3072),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_23_scratch1_array, &conv2d_23_scratch1_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_22_scratch1_array, &conv2d_22_scratch1_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_14_scratch0_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 6, 6), AI_STRIDE_INIT(4, 1, 1, 64, 384),
  1, &conv2d_11_scratch1_array, &conv2d_11_scratch1_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 768, 1, 1), AI_STRIDE_INIT(4, 1, 1, 768, 768),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1185, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1185, 1185),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 1, 1, 448, 448),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_6_scratch1_array, &conv2d_6_scratch1_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1185, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1185, 1185),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_5_scratch1_array, &conv2d_5_scratch1_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 384, 1, 1), AI_STRIDE_INIT(4, 1, 1, 384, 384),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 593, 1, 1), AI_STRIDE_INIT(4, 1, 1, 593, 593),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 25, 25), AI_STRIDE_INIT(4, 1, 1, 16, 400),
  1, &conv2d_2_scratch1_array, &conv2d_2_scratch1_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 1, 1, 192, 192),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 25, 25), AI_STRIDE_INIT(4, 1, 1, 8, 200),
  1, &conv2d_1_scratch1_array, &conv2d_1_scratch1_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 297, 1, 1), AI_STRIDE_INIT(4, 1, 1, 297, 297),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 292, 1, 1), AI_STRIDE_INIT(4, 1, 1, 292, 292),
  1, &conv2d_0_scratch0_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  dense_32_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &dense_32_bias_array, &dense_32_bias_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  dense_32_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 256, 2, 1, 1), AI_STRIDE_INIT(4, 1, 256, 512, 512),
  1, &dense_32_weights_array, &dense_32_weights_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_30_bias_array, &conv2d_30_bias_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 256, 1, 1, 256), AI_STRIDE_INIT(4, 1, 256, 256, 256),
  1, &conv2d_30_weights_array, &conv2d_30_weights_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_29_bias_array, &conv2d_29_bias_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 768, 2304),
  1, &conv2d_29_weights_array, &conv2d_29_weights_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_28_bias_array, &conv2d_28_bias_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_28_weights_array, &conv2d_28_weights_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_25_bias_array, &conv2d_25_bias_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_25_weights_array, &conv2d_25_weights_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_24_bias_array, &conv2d_24_bias_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_24_weights_array, &conv2d_24_weights_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_22_bias_array, &conv2d_22_bias_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_22_weights_array, &conv2d_22_weights_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_20_bias_array, &conv2d_20_bias_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_20_weights_array, &conv2d_20_weights_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_14_bias_array, &conv2d_14_bias_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_14_weights_array, &conv2d_14_weights_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_12_bias_array, &conv2d_12_bias_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_12_weights_array, &conv2d_12_weights_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_11_bias_array, &conv2d_11_bias_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_11_weights_array, &conv2d_11_weights_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 64), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_6_bias_array, &conv2d_6_bias_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_6_weights_array, &conv2d_6_weights_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 32), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 16), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_1_bias_array, &conv2d_1_bias_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 3, 3, 1), AI_STRIDE_INIT(4, 1, 8, 24, 72),
  1, &conv2d_1_weights_array, &conv2d_1_weights_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_0_bias_array, &conv2d_0_bias_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 1, 1, 3, 9),
  1, &conv2d_0_weights_array, &conv2d_0_weights_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_x0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 50, 50), AI_STRIDE_INIT(4, 1, 1, 1, 50),
  1, &serving_default_x0_output_array, &serving_default_x0_output_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 25, 25), AI_STRIDE_INIT(4, 1, 1, 8, 200),
  1, &conv2d_0_output_array, &conv2d_0_output_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 25, 25), AI_STRIDE_INIT(4, 1, 1, 8, 200),
  1, &conv2d_1_output_array, &conv2d_1_output_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 25, 25), AI_STRIDE_INIT(4, 1, 1, 16, 400),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 12, 12), AI_STRIDE_INIT(4, 1, 1, 16, 192),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_6_output_array, &conv2d_6_output_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 6, 6), AI_STRIDE_INIT(4, 1, 1, 32, 192),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 6, 6), AI_STRIDE_INIT(4, 1, 1, 64, 384),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 6, 6), AI_STRIDE_INIT(4, 1, 1, 64, 384),
  1, &conv2d_11_output_array, &conv2d_11_output_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 6, 6), AI_STRIDE_INIT(4, 1, 1, 64, 384),
  1, &conv2d_12_output_array, &conv2d_12_output_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 3, 3), AI_STRIDE_INIT(4, 1, 1, 64, 192),
  1, &conv2d_14_output_array, &conv2d_14_output_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_20_output_array, &conv2d_20_output_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_22_output_array, &conv2d_22_output_intq)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_24_output_array, &conv2d_24_output_intq)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_25_output_array, &conv2d_25_output_intq)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_28_output_array, &conv2d_28_output_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_29_output_array, &conv2d_29_output_intq)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_30_output_array, &conv2d_30_output_intq)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  dense_32_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &dense_32_output_array, &dense_32_output_intq)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  dense_32_fmt_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &dense_32_fmt_output_array, NULL)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  nl_33_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &nl_33_output_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  nl_33_fmt_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &nl_33_fmt_output_array, &nl_33_fmt_output_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_x0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_0_weights, &conv2d_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_0_layer, 0,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_1_layer, AI_STATIC,
  .tensors = &conv2d_0_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)


AI_STATIC_CONST ai_i8 conv2d_1_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_1_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_1_nl_params_data, conv2d_1_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_1_scratch0, &conv2d_1_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 1,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC,
  .tensors = &conv2d_1_chain, 
  .groups = 8, 
  .nl_params = &conv2d_1_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_2_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_2_nl_params_data, conv2d_2_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, &conv2d_2_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC,
  .tensors = &conv2d_2_chain, 
  .groups = 1, 
  .nl_params = &conv2d_2_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC,
  .tensors = &conv2d_4_chain, 
  .groups = 16, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_5_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_5_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_5_nl_params_data, conv2d_5_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_scratch0, &conv2d_5_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC,
  .tensors = &conv2d_5_chain, 
  .groups = 1, 
  .nl_params = &conv2d_5_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_6_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_6_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_6_nl_params_data, conv2d_6_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_6_scratch0, &conv2d_6_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 6,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC,
  .tensors = &conv2d_6_chain, 
  .groups = 32, 
  .nl_params = &conv2d_6_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC,
  .tensors = &conv2d_7_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC,
  .tensors = &conv2d_9_chain, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_11_layer, AI_STATIC,
  .tensors = &conv2d_10_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_11_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_11_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_11_nl_params_data, conv2d_11_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_11_scratch0, &conv2d_11_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 11,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_12_layer, AI_STATIC,
  .tensors = &conv2d_11_chain, 
  .groups = 64, 
  .nl_params = &conv2d_11_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 12,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_14_layer, AI_STATIC,
  .tensors = &conv2d_12_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 14,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC,
  .tensors = &conv2d_14_chain, 
  .groups = 64, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC,
  .tensors = &conv2d_15_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC,
  .tensors = &conv2d_16_chain, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC,
  .tensors = &conv2d_17_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_19_layer, AI_STATIC,
  .tensors = &conv2d_18_chain, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_19_weights, &conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_19_layer, 19,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_20_layer, AI_STATIC,
  .tensors = &conv2d_19_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 20,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC,
  .tensors = &conv2d_20_chain, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_22_layer, AI_STATIC,
  .tensors = &conv2d_21_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_22_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_22_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_22_nl_params_data, conv2d_22_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_22_scratch0, &conv2d_22_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC,
  .tensors = &conv2d_22_chain, 
  .groups = 128, 
  .nl_params = &conv2d_22_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_23_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_23_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_23_nl_params_data, conv2d_23_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_23_scratch0, &conv2d_23_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 23,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_24_layer, AI_STATIC,
  .tensors = &conv2d_23_chain, 
  .groups = 1, 
  .nl_params = &conv2d_23_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 24,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC,
  .tensors = &conv2d_24_chain, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 25,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC,
  .tensors = &conv2d_25_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 27,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_28_layer, AI_STATIC,
  .tensors = &conv2d_27_chain, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 28,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_29_layer, AI_STATIC,
  .tensors = &conv2d_28_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 29,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_30_layer, AI_STATIC,
  .tensors = &conv2d_29_chain, 
  .groups = 256, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 30,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &dense_32_layer, AI_STATIC,
  .tensors = &conv2d_30_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_32_weights, &dense_32_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_32_layer, 32,
  DENSE_TYPE,
  dense, forward_dense_integer_SSSA,
  &AI_NET_OBJ_INSTANCE, &dense_32_fmt_layer, AI_STATIC,
  .tensors = &dense_32_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_32_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_32_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_32_fmt_layer, 32,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &nl_33_layer, AI_STATIC,
  .tensors = &dense_32_fmt_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_32_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_33_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_33_layer, 33,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &nl_33_fmt_layer, AI_STATIC,
  .tensors = &nl_33_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_33_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_33_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_33_fmt_layer, 33,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &nl_33_fmt_layer, AI_STATIC,
  .tensors = &nl_33_fmt_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 218920, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 10816, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_x0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &nl_33_fmt_output),
  &conv2d_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, AI_NETWORK_ACTIVATIONS_ALIGNMENT));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    conv2d_30_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_30_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data = AI_PTR(activations + 128);
    conv2d_28_scratch0_array.data_start = AI_PTR(activations + 128);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 4096);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 4096);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 1152);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 1152);
    conv2d_24_scratch0_array.data = AI_PTR(activations + 5248);
    conv2d_24_scratch0_array.data_start = AI_PTR(activations + 5248);
    conv2d_23_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 2304);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 2304);
    conv2d_22_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_22_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 4096);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 4096);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 1152);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 1152);
    conv2d_20_scratch0_array.data = AI_PTR(activations + 4096);
    conv2d_20_scratch0_array.data_start = AI_PTR(activations + 4096);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 1152);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 1152);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 4096);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 4096);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 1152);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 1152);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 3264);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 3264);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 576);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 576);
    conv2d_14_scratch0_array.data = AI_PTR(activations + 3200);
    conv2d_14_scratch0_array.data_start = AI_PTR(activations + 3200);
    conv2d_12_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_12_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_11_scratch1_array.data = AI_PTR(activations + 5444);
    conv2d_11_scratch1_array.data_start = AI_PTR(activations + 5444);
    conv2d_11_scratch0_array.data = AI_PTR(activations + 3072);
    conv2d_11_scratch0_array.data_start = AI_PTR(activations + 3072);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_6_scratch1_array.data = AI_PTR(activations + 1856);
    conv2d_6_scratch1_array.data_start = AI_PTR(activations + 1856);
    conv2d_6_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_6_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_5_scratch1_array.data = AI_PTR(activations + 2688);
    conv2d_5_scratch1_array.data_start = AI_PTR(activations + 2688);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 2304);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 2304);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 10220);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 10220);
    conv2d_2_scratch1_array.data = AI_PTR(activations + 208);
    conv2d_2_scratch1_array.data_start = AI_PTR(activations + 208);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 10624);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 10624);
    conv2d_1_scratch1_array.data = AI_PTR(activations + 5624);
    conv2d_1_scratch1_array.data_start = AI_PTR(activations + 5624);
    conv2d_1_scratch0_array.data = AI_PTR(activations + 5324);
    conv2d_1_scratch0_array.data_start = AI_PTR(activations + 5324);
    conv2d_0_scratch0_array.data = AI_PTR(activations + 32);
    conv2d_0_scratch0_array.data_start = AI_PTR(activations + 32);
    serving_default_x0_output_array.data = AI_PTR(NULL);
    serving_default_x0_output_array.data_start = AI_PTR(NULL);
    conv2d_0_output_array.data = AI_PTR(activations + 324);
    conv2d_0_output_array.data_start = AI_PTR(activations + 324);
    conv2d_1_output_array.data = AI_PTR(activations + 5624);
    conv2d_1_output_array.data_start = AI_PTR(activations + 5624);
    conv2d_2_output_array.data = AI_PTR(activations + 208);
    conv2d_2_output_array.data_start = AI_PTR(activations + 208);
    conv2d_4_output_array.data = AI_PTR(activations + 0);
    conv2d_4_output_array.data_start = AI_PTR(activations + 0);
    conv2d_5_output_array.data = AI_PTR(activations + 2688);
    conv2d_5_output_array.data_start = AI_PTR(activations + 2688);
    conv2d_6_output_array.data = AI_PTR(activations + 1856);
    conv2d_6_output_array.data_start = AI_PTR(activations + 1856);
    conv2d_7_output_array.data = AI_PTR(activations + 1440);
    conv2d_7_output_array.data_start = AI_PTR(activations + 1440);
    conv2d_9_output_array.data = AI_PTR(activations + 6048);
    conv2d_9_output_array.data_start = AI_PTR(activations + 6048);
    conv2d_10_output_array.data = AI_PTR(activations + 768);
    conv2d_10_output_array.data_start = AI_PTR(activations + 768);
    conv2d_11_output_array.data = AI_PTR(activations + 7748);
    conv2d_11_output_array.data_start = AI_PTR(activations + 7748);
    conv2d_12_output_array.data = AI_PTR(activations + 896);
    conv2d_12_output_array.data_start = AI_PTR(activations + 896);
    conv2d_14_output_array.data = AI_PTR(activations + 0);
    conv2d_14_output_array.data_start = AI_PTR(activations + 0);
    conv2d_15_output_array.data = AI_PTR(activations + 2112);
    conv2d_15_output_array.data_start = AI_PTR(activations + 2112);
    conv2d_16_output_array.data = AI_PTR(activations + 0);
    conv2d_16_output_array.data_start = AI_PTR(activations + 0);
    conv2d_17_output_array.data = AI_PTR(activations + 2944);
    conv2d_17_output_array.data_start = AI_PTR(activations + 2944);
    conv2d_18_output_array.data = AI_PTR(activations + 0);
    conv2d_18_output_array.data_start = AI_PTR(activations + 0);
    conv2d_19_output_array.data = AI_PTR(activations + 2944);
    conv2d_19_output_array.data_start = AI_PTR(activations + 2944);
    conv2d_20_output_array.data = AI_PTR(activations + 0);
    conv2d_20_output_array.data_start = AI_PTR(activations + 0);
    conv2d_21_output_array.data = AI_PTR(activations + 2944);
    conv2d_21_output_array.data_start = AI_PTR(activations + 2944);
    conv2d_22_output_array.data = AI_PTR(activations + 1152);
    conv2d_22_output_array.data_start = AI_PTR(activations + 1152);
    conv2d_23_output_array.data = AI_PTR(activations + 4096);
    conv2d_23_output_array.data_start = AI_PTR(activations + 4096);
    conv2d_24_output_array.data = AI_PTR(activations + 0);
    conv2d_24_output_array.data_start = AI_PTR(activations + 0);
    conv2d_25_output_array.data = AI_PTR(activations + 2944);
    conv2d_25_output_array.data_start = AI_PTR(activations + 2944);
    conv2d_27_output_array.data = AI_PTR(activations + 0);
    conv2d_27_output_array.data_start = AI_PTR(activations + 0);
    conv2d_28_output_array.data = AI_PTR(activations + 10560);
    conv2d_28_output_array.data_start = AI_PTR(activations + 10560);
    conv2d_29_output_array.data = AI_PTR(activations + 9476);
    conv2d_29_output_array.data_start = AI_PTR(activations + 9476);
    conv2d_30_output_array.data = AI_PTR(activations + 3584);
    conv2d_30_output_array.data_start = AI_PTR(activations + 3584);
    dense_32_output_array.data = AI_PTR(activations + 0);
    dense_32_output_array.data_start = AI_PTR(activations + 0);
    dense_32_fmt_output_array.data = AI_PTR(activations + 4);
    dense_32_fmt_output_array.data_start = AI_PTR(activations + 4);
    nl_33_output_array.data = AI_PTR(activations + 12);
    nl_33_output_array.data_start = AI_PTR(activations + 12);
    nl_33_fmt_output_array.data = AI_PTR(NULL);
    nl_33_fmt_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_32_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_32_bias_array.data = AI_PTR(weights + 218912);
    dense_32_bias_array.data_start = AI_PTR(weights + 218912);
    dense_32_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_32_weights_array.data = AI_PTR(weights + 218400);
    dense_32_weights_array.data_start = AI_PTR(weights + 218400);
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(weights + 217376);
    conv2d_30_bias_array.data_start = AI_PTR(weights + 217376);
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(weights + 151840);
    conv2d_30_weights_array.data_start = AI_PTR(weights + 151840);
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(weights + 150816);
    conv2d_29_bias_array.data_start = AI_PTR(weights + 150816);
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(weights + 148512);
    conv2d_29_weights_array.data_start = AI_PTR(weights + 148512);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(weights + 147488);
    conv2d_28_bias_array.data_start = AI_PTR(weights + 147488);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(weights + 114720);
    conv2d_28_weights_array.data_start = AI_PTR(weights + 114720);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 114208);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 114208);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 113056);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 113056);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(weights + 112544);
    conv2d_25_bias_array.data_start = AI_PTR(weights + 112544);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(weights + 96160);
    conv2d_25_weights_array.data_start = AI_PTR(weights + 96160);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(weights + 95648);
    conv2d_24_bias_array.data_start = AI_PTR(weights + 95648);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(weights + 94496);
    conv2d_24_weights_array.data_start = AI_PTR(weights + 94496);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 93984);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 93984);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 77600);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 77600);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(weights + 77088);
    conv2d_22_bias_array.data_start = AI_PTR(weights + 77088);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(weights + 75936);
    conv2d_22_weights_array.data_start = AI_PTR(weights + 75936);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 75424);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 75424);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 59040);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 59040);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(weights + 58528);
    conv2d_20_bias_array.data_start = AI_PTR(weights + 58528);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(weights + 57376);
    conv2d_20_weights_array.data_start = AI_PTR(weights + 57376);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 56864);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 56864);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 40480);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 40480);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 39968);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 39968);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 38816);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 38816);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 38304);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 38304);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 21920);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 21920);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 21408);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 21408);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 20256);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 20256);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 19744);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 19744);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 11552);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 11552);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(weights + 11296);
    conv2d_14_bias_array.data_start = AI_PTR(weights + 11296);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(weights + 10720);
    conv2d_14_weights_array.data_start = AI_PTR(weights + 10720);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(weights + 10464);
    conv2d_12_bias_array.data_start = AI_PTR(weights + 10464);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(weights + 6368);
    conv2d_12_weights_array.data_start = AI_PTR(weights + 6368);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(weights + 6112);
    conv2d_11_bias_array.data_start = AI_PTR(weights + 6112);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(weights + 5536);
    conv2d_11_weights_array.data_start = AI_PTR(weights + 5536);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 5280);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 5280);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 3232);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 3232);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 3104);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 3104);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 2816);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 2816);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 2688);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 2688);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 1664);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 1664);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 1536);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 1536);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 1248);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 1248);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 1120);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 1120);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 608);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 608);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 544);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 544);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 400);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 400);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 336);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 336);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 208);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 208);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(weights + 176);
    conv2d_1_bias_array.data_start = AI_PTR(weights + 176);
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(weights + 104);
    conv2d_1_weights_array.data_start = AI_PTR(weights + 104);
    conv2d_0_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_bias_array.data = AI_PTR(weights + 72);
    conv2d_0_bias_array.data_start = AI_PTR(weights + 72);
    conv2d_0_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_weights_array.data = AI_PTR(weights + 0);
    conv2d_0_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 1736406,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, &params->params);
  ok &= network_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}




#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

