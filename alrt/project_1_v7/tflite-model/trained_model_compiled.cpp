/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
// Generated on: 30.10.2021 23:15:30

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 9040;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[23];
TfLiteEvalTensor tflEvalTensors[23];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[11];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,3960 } };
const TfArray<1, float> quant0_scale = { 1, { 0.0038756127469241619, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[2] = { -1, 400, };
const TfArray<1, int> tensor_dimension1 = { 1, { 2 } };
const ALIGN(8) int32_t tensor_data2[8] = { 13194, -12798, 5095, -16229, 974, -6268, 5075, -7732, };
const TfArray<1, int> tensor_dimension2 = { 1, { 8 } };
const TfArray<8, float> quant2_scale = { 8, { 1.7812986698118038e-05, 1.3832297554472461e-05, 1.3109374776831828e-05, 1.7180869690491818e-05, 1.5610527043463662e-05, 1.5999499737517908e-05, 1.2855009117629379e-05, 1.428119412594242e-05, } };
const TfArray<8, int> quant2_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(8) int32_t tensor_data3[16] = { -149, -2968, 529, -6120, 999, -6301, -8861, -1344, 633, -5420, -10, -226, -1784, -9774, -2760, -8533, };
const TfArray<1, int> tensor_dimension3 = { 1, { 16 } };
const TfArray<16, float> quant3_scale = { 16, { 2.8993012165301479e-05, 3.346287485328503e-05, 4.4837397581432015e-05, 2.1080502847325988e-05, 4.3772881326731294e-05, 2.6150601115659811e-05, 2.6989560865331441e-05, 4.1285235056420788e-05, 3.0969986255513504e-05, 2.5798184651648626e-05, 3.8142708945088089e-05, 4.0294060454471037e-05, 2.8688687962130643e-05, 3.9259837649296969e-05, 3.1292751373257488e-05, 2.6018828066298738e-05, } };
const TfArray<16, int> quant3_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(8) int32_t tensor_data4[3] = { -8997, 8124, -1249, };
const TfArray<1, int> tensor_dimension4 = { 1, { 3 } };
const TfArray<1, float> quant4_scale = { 1, { 2.1165355065022595e-05, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(8) int8_t tensor_data5[3*400] = { 
  -13, 38, 14, -18, 7, -10, 25, 4, -44, -35, -28, 10, 22, -42, 65, -15, -41, 73, 21, -36, 8, 9, 22, 11, -58, -48, -20, -9, 39, -114, 33, -4, 16, 122, 108, -30, -22, 14, -19, -27, -63, -29, -24, -19, 5, -93, 39, 31, -17, 69, 76, -15, -34, 1, 5, -22, -73, -23, -11, -11, 30, -59, 38, 18, 17, 84, 24, -4, 9, 7, 16, 3, -38, -42, 1, -53, 31, -77, 25, 6, -11, 85, 61, -8, 22, -30, 11, 13, -28, -3, 0, 22, -6, -21, 66, -3, 11, 72, 53, 15, -16, -30, 3, 5, -40, -45, -35, 17, 41, -127, 49, 20, -25, 61, 57, -26, 25, -4, 22, -15, -72, -37, -22, 11, -1, -22, 35, -17, 20, 64, 49, -8, -38, -20, -7, -42, -44, -5, 27, -7, -5, -121, 54, 11, -17, 92, 16, -7, 1, -28, -13, -14, -29, -24, -5, -4, 21, -73, 32, -10, -23, 50, 37, -37, -27, 20, 33, 27, -34, -20, 1, -17, 10, 53, 80, 2, -11, 23, 17, 12, -17, 11, 38, -52, -46, -38, -1, -12, 11, -8, 32, 16, -19, 65, 37, -42, -17, 32, 37, 22, -74, -76, -3, 1, -29, -41, 54, 34, -36, 33, 0, -2, -56, 8, 48, -21, -76, -2, 0, -3, -5, -53, 70, -18, 0, 27, 15, -4, 0, 17, -19, -4, -34, -58, -6, 56, 40, 45, 18, -9, 5, 74, 68, -16, -3, -13, -2, -64, -41, -14, 13, -1, -44, 38, 27, 12, -36, 75, 84, -39, -4, 17, 9, -26, -19, -46, 4, 50, 20, 18, 17, -8, -47, 49, 43, -7, 7, -17, 5, 13, -65, -59, 5, -24, 24, -73, 58, -20, -19, 45, 29, -33, 6, 24, -17, 12, -52, -46, -17, 18, -3, -25, 66, -52, -45, 69, 15, 20, 28, 0, 31, -17, -18, -36, -11, -12, -14, -57, 38, -6, -64, 84, 7, -37, -43, 20, 9, -47, -19, -9, 2, -10, 31, -37, 30, -13, -35, 59, 7, 41, -34, -11, 25, 28, -41, -29, -1, -16, 53, -64, 29, -1, -18, 49, 24, -12, -27, -24, 12, -108, -51, -25, 12, 5, -43, -114, 24, 14, 0, 106, 13, 37, -2, -10, -4, 24, -53, -51, 32, -16, 38, -3, 50, 21, -40, 67, 21, 27, -27, 4, 23, 13, -19, -67, 5, 29, -38, 9, 34, -20, 
  28, -46, -31, 2, 26, -8, -6, 13, 1, 16, 29, -23, 18, 13, -8, 10, -23, 12, -11, 15, -4, 16, -12, -6, -28, 5, 16, -24, 4, -30, 13, 5, 10, -29, -42, 11, -23, 8, 2, 41, -7, -7, 41, -29, -15, -32, -27, 20, 21, -73, -93, 26, -46, -20, 36, 1, 18, 25, 34, -52, 3, -63, 12, 19, 24, 13, -48, -10, -5, 1, -7, 10, -11, 5, 38, -34, 9, -52, -33, -19, 22, -21, -34, -5, -9, 3, 18, -16, 8, 23, 30, -45, 38, -29, 22, 14, 21, 5, -43, 32, -1, 7, 30, 26, 34, 19, 12, -12, 28, -25, 3, 24, -11, -28, -65, 19, -4, 7, 10, 0, -43, 25, 31, -11, 44, -54, 27, 22, 11, -57, -85, 24, 0, 6, -4, 71, 20, 6, 32, -33, 49, -16, -2, 17, -15, -29, -40, 20, -27, 7, 3, 34, 18, 17, 13, 1, 14, -8, -19, 37, 7, -1, -30, 14, -60, -30, 2, -11, 27, 16, 7, -14, 51, -56, 15, -8, 20, -30, -47, -9, -1, -1, -17, 28, -4, 27, 8, -11, 25, -35, -14, 17, 31, -19, -45, 18, -23, -20, -17, -5, -10, 14, 47, -28, 38, -37, -11, -1, 38, -29, -26, 59, -42, -11, 24, -13, 18, -18, 22, -43, 12, -8, 40, -15, 30, -25, -25, 25, -27, -7, 0, 50, -36, 10, 11, -10, 7, 1, -10, -8, 8, -1, -38, 0, -2, 22, -37, 5, -6, -6, 22, -41, 59, -33, 12, 10, 32, -31, -41, 28, -24, 20, -18, 59, 20, -14, 62, -8, 42, 33, 0, 0, 22, -17, -62, -8, -11, -35, 11, 24, 6, -16, 42, -33, 11, 58, 8, -8, 21, -42, -31, 11, -14, -1, 24, -31, -47, 4, 6, -20, 7, -65, 14, 15, 35, -27, -47, 21, -4, -15, -42, 17, -6, 46, 29, -32, 21, -8, 4, 5, 35, 11, -42, 24, -35, -8, -2, -9, 4, -16, 34, -45, 5, 16, 6, -23, 22, -41, -35, 20, -20, 13, 9, 3, -2, 24, 41, -33, -14, 44, 16, 30, 32, -21, -35, 8, -17, 6, 3, 41, 2, -28, 53, 7, 3, 32, 10, 13, 52, -7, -22, -14, -31, -1, -18, 21, -23, -2, 38, -32, 13, 54, 17, 24, 35, -36, -16, 35, -48, -4, 14, -6, 9, 39, 53, -19, 13, -1, 27, -21, 
  -40, -27, 37, 25, 30, 29, -14, 2, 46, -5, -60, 18, -20, 8, -56, -19, -21, -8, -3, 12, 50, -14, -24, -17, 35, 54, -56, 54, -21, 72, -58, 7, -31, -39, 13, -4, 43, 28, -12, -13, 25, 13, -21, 51, -34, 47, -46, 2, -41, -42, 30, -9, 30, 4, -27, -1, 9, 22, -45, 1, -48, 51, -30, -18, -17, -30, 32, 2, 31, 41, 7, -7, 9, 12, -16, 46, -12, 35, -58, 44, -4, -42, 13, -5, 28, 2, -20, 51, 18, -33, 3, 54, -7, 54, -62, -16, -47, -55, 58, -39, 34, 29, -11, 1, 23, 26, -50, 32, -25, 97, -93, 17, -35, -26, -22, 3, 16, 22, -9, 49, 36, 27, -40, 31, -45, 77, -57, -29, -30, -8, 44, -21, 33, 51, -30, -2, 32, -4, 1, 23, -17, 59, -87, -5, -24, -61, 5, -1, 34, 22, 43, -3, 66, 23, -33, 49, -52, 52, -51, 12, -43, -6, 46, -1, 25, 33, 16, -42, 10, 11, -3, 53, 0, -9, -21, -1, -20, -71, 18, -12, 31, 11, -39, -9, 16, 9, -38, 6, -32, 6, -48, -31, 1, -26, -5, -22, 11, -6, 22, 39, 37, 18, -27, 34, -41, 34, -34, -21, -37, -3, 57, -32, 34, -6, -22, 23, 19, 9, 4, 10, -30, -10, -121, 11, -37, -23, 27, 6, 38, -15, 2, 27, 34, -12, -10, 50, -68, -96, -33, 18, -3, -62, -10, 24, 45, 27, 10, 12, 14, 33, -11, 12, -43, 11, -59, 13, 0, -9, -4, 30, -2, 36, 22, -23, 60, 45, -2, 33, -42, -71, -61, 8, 9, -1, -2, 17, 55, 14, -25, -68, 36, 29, -16, 4, -9, -8, -75, -6, 4, -36, 51, -37, 49, -13, -22, -17, 27, -32, -4, 19, -32, 47, -54, 25, -37, -25, 46, 1, 42, 22, 44, 32, 29, 26, -16, -11, -54, 3, -53, 13, -17, -10, -22, -8, 18, -12, -4, -16, 43, -1, -34, -6, -25, -9, -65, -1, -35, -38, 76, -40, 65, 21, -5, 0, 22, 26, -22, 33, -9, -70, -42, 4, -22, -16, 33, 1, 58, 44, 28, -46, 26, 4, -21, 37, -61, -26, -74, -28, -21, -44, 23, -36, 43, -8, -21, -83, 26, 17, -28, 29, -47, -48, -27, -24, -17, -16, 43, 20, 19, -18, -13, -55, 27, 7, -32, 51, -23, -5, -36, 31, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 3,400 } };
const TfArray<1, float> quant5_scale = { 1, { 0.003734885947778821, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(8) int8_t tensor_data6[8*1*3*40] = { 
  /* [0][0][][] */ -36,14,61,-28,47,49,76,83,89,91,56,68,97,103,57,-38,-19,-1,-14,-126,-100,-54,-15,-24,-30,-17,-74,-2,-2,-28,-51,-63,-84,-4,-40,-26,-33,-23,-13,37, 17,34,61,17,4,42,91,71,67,45,67,52,19,32,68,3,29,-114,-45,-54,-127,-61,-22,-36,-36,-50,-28,-9,-5,-37,-50,16,-21,-31,-52,-50,-2,-5,7,17, -2,16,-2,16,48,34,93,21,55,45,38,81,83,68,12,3,18,-27,-27,-37,-11,12,-41,-116,-52,-29,-54,-25,-47,-3,-38,-30,-82,-46,-40,-30,64,2,37,-10, 
  /* [1][0][][] */ 62,0,16,24,0,-10,77,31,33,62,61,-84,-46,-32,-46,91,-34,-76,31,-66,-63,80,-82,-64,25,23,-46,-63,-11,54,-74,-75,32,-42,72,42,51,56,51,-29, 42,24,19,-8,17,14,49,58,59,72,54,-42,-94,-68,-45,71,-10,-69,14,-58,-36,74,-46,-27,36,11,-70,-127,-9,41,-98,-15,37,-39,73,102,20,78,56,-10, 18,23,39,4,-10,-2,41,22,48,54,50,-72,-41,-57,-42,87,-8,-73,22,-60,-93,44,-105,-50,24,15,-41,-89,8,22,-91,-30,57,-38,65,73,73,85,28,-38, 
  /* [2][0][][] */ -4,-82,-26,24,-24,9,-41,-54,-53,-33,30,127,87,0,20,-90,25,50,-2,47,22,-4,24,7,-22,-12,90,37,-35,-54,-26,39,-16,-13,-104,5,-78,-82,-13,34, -28,-7,-11,14,-13,34,-42,-72,-38,-17,7,87,80,4,28,-68,62,61,-71,43,21,-50,1,17,-8,3,46,108,4,-79,41,50,-8,20,-53,-111,5,-85,-52,35, -63,-16,-6,6,5,-25,-15,-20,-54,-69,-21,94,74,43,27,-75,-31,40,1,14,100,-51,25,30,-66,11,75,86,-22,-90,40,68,-1,41,-114,-63,-44,-124,14,29, 
  /* [3][0][][] */ 14,32,-25,40,-44,12,-17,-18,-74,-44,-46,-60,-59,0,-21,-43,-36,31,-3,100,41,-100,-23,-57,-66,-95,-127,-31,12,20,-52,16,8,25,24,78,15,52,-20,35, 11,17,25,-10,-12,-34,-21,46,-29,-71,-57,-41,-93,-60,-33,-67,-56,86,70,72,22,-39,-61,-5,-124,-80,-91,-78,-25,15,4,-28,40,7,0,11,27,19,54,-31, -30,-11,32,-25,-3,-10,-39,4,-38,22,-27,-74,-79,-25,-33,-70,-7,89,17,97,47,-57,-68,-93,-76,-107,-116,-77,-25,36,-33,-22,-54,-18,35,66,-26,61,-13,36, 
  /* [4][0][][] */ -9,-8,-20,1,-36,-88,-78,-32,28,-10,61,127,87,63,31,-67,8,-64,-5,-89,-117,-30,40,-34,41,-41,2,-2,16,-84,7,-69,19,-18,-126,-20,3,-34,38,25, -60,16,-22,4,-12,-93,-103,-86,-56,3,-30,57,69,-21,-52,-1,-60,-95,-25,13,-29,-64,-9,25,-44,25,-77,5,25,0,10,15,-33,-29,-12,-54,-1,-52,-4,-17, -1,-60,-13,-9,-29,-65,-94,-18,10,-44,-20,-2,69,49,62,-42,-34,-31,-5,-39,-27,-20,6,-63,41,-67,20,4,12,8,-28,-65,-4,17,-75,-23,1,-29,-14,15, 
  /* [5][0][][] */ 18,64,66,90,-11,22,30,82,-13,36,-9,-30,62,35,-16,-34,37,-34,-59,-9,-69,-64,20,-5,-112,-65,-4,-29,-12,66,64,9,-100,14,-69,48,18,-4,8,4, -22,18,-35,-13,27,33,83,56,72,72,2,-24,-18,37,-40,20,39,-87,5,-76,-100,-78,-57,-69,-53,11,3,41,-89,27,-37,31,-88,-10,17,27,-63,81,41,-16, -50,-14,-36,-23,28,44,40,20,75,20,19,127,50,17,-32,-6,-43,-82,-67,-57,-73,-39,24,-26,-18,-3,-34,-28,17,35,18,-25,-58,-53,28,-39,-27,26,-26,18, 
  /* [6][0][][] */ -29,-90,-87,-31,-86,-50,-34,11,-71,16,-39,-3,38,43,30,-61,-60,-99,-22,-63,-66,-50,-13,6,17,-54,-9,50,104,38,27,-7,0,105,-26,-3,6,-11,18,107, -73,-115,-64,-68,-127,-46,-63,-43,-88,-50,-49,38,11,19,2,-58,-81,-54,-16,3,-43,-44,22,-20,-28,-5,-33,34,84,34,64,12,-41,-39,-25,-25,-30,70,41,125, -61,-28,-17,-62,-46,-74,-14,10,-49,-3,23,33,-8,42,14,-116,-105,-104,-36,-33,-15,-70,-30,-35,-22,-75,28,38,102,66,90,32,-6,68,14,3,26,-32,73,107, 
  /* [7][0][][] */ 7,9,2,31,33,-17,-29,-9,-5,-47,-31,6,3,-19,-9,-2,59,89,18,21,84,18,93,95,28,30,26,2,-3,-61,-12,8,17,-4,-40,-82,-24,-127,-82,-60, 12,14,1,13,39,-9,-34,-14,3,-35,-23,-26,-14,-69,22,-12,74,80,12,27,67,20,81,48,27,40,57,4,-41,-17,20,17,23,25,-44,-90,-71,-35,-72,-78, 7,10,13,-10,10,8,-23,-48,4,-45,-66,-25,6,-25,-11,4,61,86,-3,44,55,64,53,59,-4,40,53,39,-93,-74,-14,-6,-13,-19,-46,-40,-116,-105,-81,-76, 
};
const TfArray<4, int> tensor_dimension6 = { 4, { 8,1,3,40 } };
const TfArray<8, float> quant6_scale = { 8, { 0.0045961728319525719, 0.0035690607037395239, 0.0033825295977294445, 0.004433071706444025, 0.0040278863161802292, 0.0041282502934336662, 0.0033168972004204988, 0.0036848867312073708, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(8) int8_t tensor_data7[16*1*3*8] = { 
  /* [0][0][][] */ -78,-46,-32,-31,-127,-115,77,-82, 84,-16,-12,-104,-60,-98,0,-49, 14,-64,5,-71,-27,31,43,-28, 
  /* [1][0][][] */ -127,90,-120,-124,-64,-109,-14,-3, -97,-13,-119,-40,-86,-45,-42,-54, -93,97,-90,-18,-32,-118,-33,4, 
  /* [2][0][][] */ -127,28,-25,-93,-74,-19,-67,6, -43,7,-43,-11,-40,-68,-81,86, -77,35,-89,-81,-20,-20,-82,6, 
  /* [3][0][][] */ -41,-50,18,-74,-69,127,-61,9, -127,-69,-67,-18,-19,82,86,-114, -47,-115,22,-96,-60,61,47,-103, 
  /* [4][0][][] */ -87,-28,18,39,-39,-72,-63,25, -127,-7,-29,-2,-57,-58,-42,47, -39,-40,40,49,-69,-7,-85,35, 
  /* [5][0][][] */ -17,-82,-83,-21,21,3,-25,37, -87,-87,-127,3,-30,22,-116,-124, -59,-41,-42,-41,41,-39,-100,56, 
  /* [6][0][][] */ -30,-17,-46,73,22,-27,-32,-11, -39,-25,-41,-109,-63,57,-93,-127, -88,22,-66,-78,6,-84,-34,-45, 
  /* [7][0][][] */ -113,-79,28,-69,-72,43,30,-48, -26,-77,-112,-2,5,-14,31,-53, -127,-24,-34,-57,-37,-31,21,1, 
  /* [8][0][][] */ -42,-88,74,8,4,-76,3,46, -10,-80,-23,74,37,-11,9,40, -61,-71,44,-68,-43,-127,15,9, 
  /* [9][0][][] */ -3,-44,37,-51,41,-38,-127,-40, -25,5,108,-85,-70,32,39,-84, 61,-48,62,-6,52,-28,16,-27, 
  /* [10][0][][] */ 36,-19,4,-78,32,-23,-20,-18, 67,1,-1,-38,31,38,58,-28, 40,-8,0,-127,-11,18,42,-44, 
  /* [11][0][][] */ -59,-34,-13,61,-64,-71,-46,12, -102,-1,8,0,-127,-24,-67,45, -82,14,-52,47,-18,-82,-51,31, 
  /* [12][0][][] */ 26,1,-127,-91,-24,24,58,-52, -126,-31,7,-83,-41,-84,28,-59, -55,-2,-107,-107,-105,-7,65,-51, 
  /* [13][0][][] */ -45,-57,-13,52,-106,-28,-51,-97, -90,-41,-30,12,-37,-83,-72,0, -127,-31,-35,48,-18,-14,-22,-66, 
  /* [14][0][][] */ -18,65,-34,-48,-93,90,3,-127, 12,30,-120,-81,8,-19,-5,-78, -17,104,-44,-65,7,20,-7,-65, 
  /* [15][0][][] */ 12,-29,-69,-4,-81,-127,-94,-69, -89,-49,-74,-100,34,29,27,3, 20,-97,-15,-80,-55,15,-88,-7, 
};
const TfArray<4, int> tensor_dimension7 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant7_scale = { 16, { 0.003241807222366333, 0.0037415977567434311, 0.005013421643525362, 0.002357082674279809, 0.0048943944275379181, 0.0029239875730127096, 0.0030177945736795664, 0.0046162423677742481, 0.0034628594294190407, 0.0028845826163887978, 0.0042648660019040108, 0.0045054159127175808, 0.0032077797222882509, 0.0043897759169340134, 0.0034989488776773214, 0.0029092535842210054, } };
const TfArray<16, int> quant7_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(8) int32_t tensor_data8[4] = { 1, 1, 99, 40, };
const TfArray<1, int> tensor_dimension8 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data9[4] = { 1, 99, 1, 8, };
const TfArray<1, int> tensor_dimension9 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data10[4] = { 1, 1, 50, 8, };
const TfArray<1, int> tensor_dimension10 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data11[4] = { 1, 50, 1, 16, };
const TfArray<1, int> tensor_dimension11 = { 1, { 4 } };
const TfArray<4, int> tensor_dimension12 = { 4, { 1,1,99,40 } };
const TfArray<1, float> quant12_scale = { 1, { 0.0038756127469241619, } };
const TfArray<1, int> quant12_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<4, int> tensor_dimension13 = { 4, { 1,1,99,8 } };
const TfArray<1, float> quant13_scale = { 1, { 0.0089434720575809479, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<4, int> tensor_dimension14 = { 4, { 1,99,1,8 } };
const TfArray<1, float> quant14_scale = { 1, { 0.0089434720575809479, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfArray<4, int> tensor_dimension15 = { 4, { 1,50,1,8 } };
const TfArray<1, float> quant15_scale = { 1, { 0.0089434720575809479, } };
const TfArray<1, int> quant15_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant15 = { (TfLiteFloatArray*)&quant15_scale, (TfLiteIntArray*)&quant15_zero, 0 };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,50,8 } };
const TfArray<1, float> quant16_scale = { 1, { 0.0089434720575809479, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,50,16 } };
const TfArray<1, float> quant17_scale = { 1, { 0.0056669348850846291, } };
const TfArray<1, int> quant17_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<4, int> tensor_dimension18 = { 4, { 1,50,1,16 } };
const TfArray<1, float> quant18_scale = { 1, { 0.0056669348850846291, } };
const TfArray<1, int> quant18_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<4, int> tensor_dimension19 = { 4, { 1,25,1,16 } };
const TfArray<1, float> quant19_scale = { 1, { 0.0056669348850846291, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<2, int> tensor_dimension20 = { 2, { 1,400 } };
const TfArray<1, float> quant20_scale = { 1, { 0.0056669348850846291, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<2, int> tensor_dimension21 = { 2, { 1,3 } };
const TfArray<1, float> quant21_scale = { 1, { 0.091920264065265656, } };
const TfArray<1, int> quant21_zero = { 1, { -32 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<2, int> tensor_dimension22 = { 2, { 1,3 } };
const TfArray<1, float> quant22_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,8 } };
const TfArray<1, int> outputs0 = { 1, { 12 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 12,6,2 } };
const TfArray<1, int> outputs1 = { 1, { 13 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 13,9 } };
const TfArray<1, int> outputs2 = { 1, { 14 } };
const TfLitePoolParams opdata3 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs3 = { 1, { 14 } };
const TfArray<1, int> outputs3 = { 1, { 15 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 15,10 } };
const TfArray<1, int> outputs4 = { 1, { 16 } };
const TfLiteConvParams opdata5 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs5 = { 3, { 16,7,3 } };
const TfArray<1, int> outputs5 = { 1, { 17 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 17,11 } };
const TfArray<1, int> outputs6 = { 1, { 18 } };
const TfLitePoolParams opdata7 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs7 = { 1, { 18 } };
const TfArray<1, int> outputs7 = { 1, { 19 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 19,1 } };
const TfArray<1, int> outputs8 = { 1, { 20 } };
const TfLiteFullyConnectedParams opdata9 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs9 = { 3, { 20,5,4 } };
const TfArray<1, int> outputs9 = { 1, { 21 } };
const TfLiteSoftmaxParams opdata10 = { 1 };
const TfArray<1, int> inputs10 = { 1, { 21 } };
const TfArray<1, int> outputs10 = { 1, { 22 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 3968, (TfLiteIntArray*)&tensor_dimension0, 3960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 12, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 1200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension12, 3960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 3968, (TfLiteIntArray*)&tensor_dimension13, 792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant14))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension15, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant15))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension17, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension19, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension21, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers.push_back(ptr);
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    return kTfLiteError;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 23;
  for(size_t i = 0; i < 23; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for(size_t i = 0; i < 11; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
    tflNodes[i].custom_initial_data = nullptr;
    tflNodes[i].custom_initial_data_size = 0;
    if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 11; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  22, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 11; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}
