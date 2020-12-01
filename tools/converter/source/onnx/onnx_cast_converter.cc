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

#include "onnx/onnx_utils.h"
#include "tnn/interpreter/tnn/objseri.h"
#include "tools/converter/source/onnx/onnx_base_converter.h"

namespace TNN_CONVERTER {
DECLARE_OP_CONVERTER(Cast);

std::string OnnxCastConverter::TNNOpType(const onnx::NodeProto &node, bool quantized_model) {
    return "Cast";
}

TNN_NS::ActivationType OnnxCastConverter::ActivationType(const onnx::NodeProto &node) {
    return TNN_NS::ActivationType_None;
}

TNN_NS::Status OnnxCastConverter::exec(tnn::NetStructure &net_structure, tnn::NetResource &net_resource,
                                       const onnx::NodeProto &node,
                                       std::map<std::string, const onnx::TensorProto *> &proxy_initializers_map,
                                       std::map<std::string, std::shared_ptr<OnnxProxyNode>> &proxy_nodes,
                                       bool &quantized_model) {
    const std::string &onnx_op = node.op_type();
    auto param                 = new TNN_NS::CastLayerParam;
    auto cur_layer             = net_structure.layers.back();
    cur_layer->param           = std::shared_ptr<TNN_NS::LayerParam>(param);
    param->type                = cur_layer->type_str;
    param->name                = cur_layer->name;
    param->quantized           = false;

    auto to_type = GetAttributeInt(node, "to", 0);
    param->to    = TensorProtoDataType2TnnDataType(to_type);

    cur_layer->inputs[0] = node.input(0);

    return TNN_NS::TNN_CONVERT_OK;
}

REGISTER_CONVERTER(Cast, Cast);

}  // namespace TNN_CONVERTER