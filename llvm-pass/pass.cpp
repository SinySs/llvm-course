#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

namespace llvm {
namespace {
    struct my_pass : public FunctionPass {
        static char ID;
        my_pass() : FunctionPass(ID) {}

        bool is_function_logger(StringRef name) {
            return name == "log_function";
        }

        virtual bool runOnFunction(Function &F) {
            if (is_function_logger(F.getName())) {
                return false;
            }

            LLVMContext &ctx = F.getContext();
            IRBuilder<> builder(ctx);
            Type *ret_type = Type::getVoidTy(ctx);

            ArrayRef<Type *> log_param_type_arr = {builder.getInt8Ty()->getPointerTo()};
            FunctionType *log_function_type = FunctionType::get(ret_type, log_param_type_arr, false);
            FunctionCallee log_function = F.getParent()->getOrInsertFunction("log_function", log_function_type);

            for (auto &B : F) {
                for (auto &I : B) {
                    if (auto *phi = dyn_cast<PHINode>(&I)) {
                        continue;
                    }

                    builder.SetInsertPoint(&I);

                    Value *op_name = builder.CreateGlobalStringPtr(I.getOpcodeName());
                    if (op_name) {
                        Value *args[] = {op_name};
                        builder.CreateCall(log_function, args);
                    }
                }
            }
            return true;

        }
    };

} // namespace

char my_pass::ID = 0;
static void registerMyPass(const PassManagerBuilder &, legacy::PassManagerBase &PM) {
  PM.add(new my_pass());
}
static RegisterStandardPasses RegisterMyPass(PassManagerBuilder::EP_OptimizerLast, registerMyPass);

} // namespace llvm
