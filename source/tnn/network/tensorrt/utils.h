// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef TNN_SOURCE_TNN_NETWORK_TENSORRT_UTILS_H_
#define TNN_SOURCE_TNN_NETWORK_TENSORRT_UTILS_H_

#include "tnn/core/common.h"

namespace TNN_NS {

std::string GetGpuType(int gpu_id);

std::string GetGpuArch(int gpu_id);

std::string GetCudaVersion();

std::string GetTrtVersion();

DataType ConvertTRTDataType(nvinfer1::DataType type);

DataFormat ConvertTRTDataFormat(nvinfer1::TensorFormat format);

nvinfer1::Dims ConvertToTRTDims(DimsVector dims);

nvinfer1::Dims ConvertToTRTDynamicDims(DimsVector dims);

nvinfer1::DataType ConvertToTRTDataType(DataType type);

}  //  namespace TNN_NS

#endif  //  TNN_SOURCE_TNN_NETWORK_TENSORRT_UTILS_H_