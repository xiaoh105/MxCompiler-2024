#include "opt/reg_alloc/coalesce_graph.h"

RegisterNode::RegisterNode(std::shared_ptr<Register> reg) : register_(std::move(reg)) {
  precolored_ = std::dynamic_pointer_cast<MachineRegister *>(register_) != nullptr;
}
