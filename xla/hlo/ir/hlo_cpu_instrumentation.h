/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_XLA_SERVICE_HLO_CPU_INSTRUMENTATION_H_
#define TENSORFLOW_COMPILER_XLA_SERVICE_HLO_CPU_INSTRUMENTATION_H_

#include "absl/container/flat_hash_map.h"
#include "xla/hlo/ir/hlo_computation.h"
#include "xla/hlo/ir/hlo_instruction.h"
#include "xla/hlo/ir/hlo_module.h"
#include "xla/service/hlo_pass_interface.h"
#include "xla/statusor.h"

namespace xla {

class HloCpuInstr : public HloModulePass {
 public:
  HloCpuInstr() {}
  ~HloCpuInstr() override {}
  absl::string_view name() const override { return "cpu_instrumentation"; }

  // Run CPU instrumentation on a computation.
  static StatusOr<bool> RunOnComputation(HloComputation* computation);

  // Run the pass on the given module.
  using HloPassInterface::Run;
  StatusOr<bool> Run(
      HloModule* module,
      const absl::flat_hash_set<absl::string_view>& execution_threads) override;

  //  private:
};
}  // namespace xla

#endif  // TENSORFLOW_COMPILER_XLA_SERVICE_CPU_INSTRUMENTATION_H_
