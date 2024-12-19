#include "graphics.h"

#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

int main()
{
    LLVMContext context;
    Module *module = new Module("app.c", context);
    IRBuilder<> builder(context);

    Type *voidType = Type::getVoidTy(context);
    ArrayRef<Type *> simPutPixelParamTypes = {Type::getInt32Ty(context),
                                              Type::getInt32Ty(context),
                                              Type::getInt32Ty(context)};
    FunctionType *simPutPixelType =
        FunctionType::get(voidType, simPutPixelParamTypes, false);
    FunctionCallee simPutPixelFunc =
        module->getOrInsertFunction("put_pixel", simPutPixelType);

    // declare void @simFlush()
    FunctionType *simFlushType = FunctionType::get(voidType, false);
    FunctionCallee simFlushFunc =
        module->getOrInsertFunction("flush", simFlushType);

    ArrayType *arrayType = ArrayType::get(Type::getInt32Ty(context), 40000);

    GlobalVariable *grid = new GlobalVariable(
        *module, arrayType, false, GlobalValue::InternalLinkage,
        Constant::getNullValue(arrayType), "grid", nullptr,
        GlobalValue::NotThreadLocal, 16);
    GlobalVariable *new_grid = new GlobalVariable(
        *module, arrayType, false, GlobalValue::InternalLinkage,
        Constant::getNullValue(arrayType), "new_grid", nullptr,
        GlobalValue::NotThreadLocal, 16);
    // define void @app() {
    FunctionType *appFuncType = FunctionType::get(voidType, false);
    Function *appFunc =
        Function::Create(appFuncType, Function::ExternalLinkage, "app", module);

    // BasicBlocks:
    BasicBlock *BB0 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB15 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB18 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB19 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB22 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB25 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB28 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB31 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB34 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB37 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB40 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB43 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB52 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB55 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB58 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB61 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB64 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB67 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB70 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB73 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB82 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB83 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB86 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB87 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB90 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB91 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB94 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB95 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB98 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB99 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB102 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB103 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB106 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB107 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB110 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB113 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB116 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB117 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB137 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB140 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB141 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB144 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB154 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB157 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB160 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB167 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB175 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB176 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB179 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB180 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB183 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB184 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB187 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB195 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB198 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB199 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB202 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB203 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB206 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB216 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB219 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB220 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB223 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB224 = BasicBlock::Create(context, "", appFunc);

    Type *i32 = Type::getInt32Ty(context);

    Type *i64 = Type::getInt64Ty(context);
    // 0:
    builder.SetInsertPoint(BB0);
    // br label %1
    AllocaInst *var1 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var2 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var3 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var4 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var5 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var6 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var7 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var8 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var9 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var10 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var11 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var12 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var13 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");
    AllocaInst *var14 = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, "");

    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1600)}));
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1601)}));
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1602)}));
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1403)}));
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1202)}));
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1005)}));
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1206)}));
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1404)}));
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1405)}));
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 1406)}));
    builder.CreateStore(ConstantInt::get(i32, 0), var1);

    builder.CreateBr(BB15);

    // 15:                                                ; preds = %7
    builder.SetInsertPoint(BB15);

    Value *var16 = builder.CreateLoad(i32, var1, "");                          
    Value *cond = builder.CreateICmpSLT(var16, ConstantInt::get(i32, 13), ""); 

    builder.CreateCondBr(cond, BB18, BB90);

    builder.SetInsertPoint(BB18);
    builder.CreateStore(ConstantInt::get(i32, 0), var2); 
    builder.CreateBr(BB19);                              

    // 19
    builder.SetInsertPoint(BB19);
    Value *var20 = builder.CreateLoad(i32, var2, "");
    Value *cond20 = builder.CreateICmpSLT(var20, ConstantInt::get(i32, 13), "");
    builder.CreateCondBr(cond20, BB22, BB86);

    // 22:                                               ; preds = %19
    builder.SetInsertPoint(BB22);
    Value *var23 = builder.CreateLoad(i32, var1, "");
    Value *cond24 = builder.CreateICmpEQ(var23, ConstantInt::get(i32, 0), "");
    builder.CreateCondBr(cond24, BB31, BB25);

    // 25:                                               ; preds = %22
    builder.SetInsertPoint(BB25);
    Value *var26 = builder.CreateLoad(i32, var1, "");
    Value *cond27 = builder.CreateICmpEQ(var26, ConstantInt::get(i32, 6), "");
    builder.CreateCondBr(cond27, BB31, BB28);

    // 28:                                               ; preds = %25
    builder.SetInsertPoint(BB28);
    Value *var29 = builder.CreateLoad(i32, var1, "");
    Value *cond30 = builder.CreateICmpEQ(var29, ConstantInt::get(i32, 12), "");
    builder.CreateCondBr(cond30, BB31, BB52);

    // 31:                                               ; preds = %28, %25, %22
    builder.SetInsertPoint(BB31);
    Value *var32 = builder.CreateLoad(i32, var2, "");
    Value *cond33 = builder.CreateICmpSGT(var32, ConstantInt::get(i32, 0), "");
    builder.CreateCondBr(cond33, BB34, BB37);

    // 34:                                               ; preds = %31
    builder.SetInsertPoint(BB34);
    Value *var35 = builder.CreateLoad(i32, var2, "");
    Value *cond36 = builder.CreateICmpSLT(var35, ConstantInt::get(i32, 6), "");
    builder.CreateCondBr(cond36, BB43, BB37);

    // 37:                                               ; preds = %34, %31
    builder.SetInsertPoint(BB37);
    Value *var38 = builder.CreateLoad(i32, var2, "");
    Value *cond39 = builder.CreateICmpSGT(var38, ConstantInt::get(i32, 7), "");
    builder.CreateCondBr(cond39, BB40, BB52);

    // 40:                                               ; preds = %37
    builder.SetInsertPoint(BB40);
    Value *var41 = builder.CreateLoad(i32, var2, "");
    Value *cond42 = builder.CreateICmpSLT(var41, ConstantInt::get(i32, 13), "");
    builder.CreateCondBr(cond42, BB43, BB52);

    // 43:                                               ; preds = %40, %34
    builder.SetInsertPoint(BB43);
    Value *var44 = builder.CreateLoad(i32, var1, "");
    Value *var45 = builder.CreateAdd(var44, ConstantInt::get(i32, 50), "");
    Value *var46 = builder.CreateMul(var45, ConstantInt::get(i32, 200), "");
    Value *var47 = builder.CreateLoad(i32, var2, "");
    Value *var48 = builder.CreateAdd(var47, ConstantInt::get(i32, 50), "");
    Value *var49 = builder.CreateAdd(var46, var48, "");
    Value *var50 = builder.CreateSExt(var49, i64, "");
    Value *var51 = builder.CreateGEP(grid, {ConstantInt::get(i64, 0), var50}, "");
    builder.CreateStore(ConstantInt::get(i32, 1), var51);
    builder.CreateBr(BB52);

    // 52:                                               ; preds = %43, %40, %37, %28
    builder.SetInsertPoint(BB52);
    Value *var53 = builder.CreateLoad(i32, var2, "");
    Value *cond54 = builder.CreateICmpEQ(var53, ConstantInt::get(i32, 0), "");
    builder.CreateCondBr(cond54, BB61, BB55);

    // 55:                                               ; preds = %52
    builder.SetInsertPoint(BB55);
    Value *var56 = builder.CreateLoad(i32, var2, "");
    Value *cond57 = builder.CreateICmpEQ(var56, ConstantInt::get(i32, 6), "");
    builder.CreateCondBr(cond57, BB61, BB58);

    // 58:                                               ; preds = %55
    builder.SetInsertPoint(BB58);
    Value *var59 = builder.CreateLoad(i32, var2, "");
    Value *cond60 = builder.CreateICmpEQ(var59, ConstantInt::get(i32, 12), "");
    builder.CreateCondBr(cond60, BB61, BB82);

    // 61:                                               ; preds = %58, %55, %52
    builder.SetInsertPoint(BB61);
    Value *var62 = builder.CreateLoad(i32, var1, "");
    Value *cond63 = builder.CreateICmpSGT(var62, ConstantInt::get(i32, 0), "");
    builder.CreateCondBr(cond63, BB64, BB67);

    // 64:                                               ; preds = %61
    builder.SetInsertPoint(BB64);
    Value *var65 = builder.CreateLoad(i32, var1, "");
    Value *cond66 = builder.CreateICmpSLT(var65, ConstantInt::get(i32, 6), "");
    builder.CreateCondBr(cond66, BB73, BB67);

    // 67:                                               ; preds = %64, %61
    builder.SetInsertPoint(BB67);
    Value *var68 = builder.CreateLoad(i32, var1, "");
    Value *cond69 = builder.CreateICmpSGT(var68, ConstantInt::get(i32, 7), "");
    builder.CreateCondBr(cond69, BB70, BB82);

    // 70:                                               ; preds = %67
    builder.SetInsertPoint(BB70);
    Value *var71 = builder.CreateLoad(i32, var1, "");
    Value *cond72 = builder.CreateICmpSLT(var71, ConstantInt::get(i32, 13), "");
    builder.CreateCondBr(cond72, BB73, BB82);

    // 73:                                               ; preds = %70, %64
    builder.SetInsertPoint(BB73);
    Value *var74 = builder.CreateLoad(i32, var1, "");
    Value *var75 = builder.CreateAdd(var74, ConstantInt::get(i32, 50), "");
    Value *var76 = builder.CreateMul(var75, ConstantInt::get(i32, 200), "");
    Value *var77 = builder.CreateLoad(i32, var2, "");
    Value *var78 = builder.CreateAdd(var77, ConstantInt::get(i32, 50), "");
    Value *var79 = builder.CreateAdd(var76, var78, "");
    Value *var80 = builder.CreateSExt(var79, i64, "");
    Value *var81 = builder.CreateGEP(grid, {ConstantInt::get(i64, 0), var80}, "");
    builder.CreateStore(ConstantInt::get(i32, 1), var81);
    builder.CreateBr(BB82);

    // 82:                                               ; preds = %73, %70, %67, %58
    builder.SetInsertPoint(BB82);
    builder.CreateBr(BB83);

    // 83:                                               ; preds = %82
    builder.SetInsertPoint(BB83);
    Value *var84 = builder.CreateLoad(i32, var2, "");
    Value *var85 = builder.CreateAdd(var84, ConstantInt::get(i32, 1), "");
    builder.CreateStore(var85, var2);
    builder.CreateBr(BB19);

    // 86:                                               ; preds = %19
    builder.SetInsertPoint(BB86);
    builder.CreateBr(BB87);

    // 87:                                               ; preds = %86
    builder.SetInsertPoint(BB87);
    Value *var88 = builder.CreateLoad(i32, var1, "");
    Value *var89 = builder.CreateAdd(var88, ConstantInt::get(i32, 1), "");
    builder.CreateStore(var89, var1);
    builder.CreateBr(BB15);

    // 90:                                               ; preds = %15
    builder.SetInsertPoint(BB90);
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 8040)}), 16);
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 8041)}), 4);
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 8239)}), 4);
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 8242)}), 8);
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 8440)}), 16);
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 8441)}), 4);
    builder.CreateStore(ConstantInt::get(i32, 1), builder.CreateGEP(grid, {ConstantInt::get(i64, 0), ConstantInt::get(i64, 8641)}), 4);
    builder.CreateStore(ConstantInt::get(i32, 1), var3);
    builder.CreateBr(BB91);

    // 91:                                               ; preds = %223, %90
    builder.SetInsertPoint(BB91);
    Value *var92 = builder.CreateLoad(i32, var3, "");
    Value *cond93 = builder.CreateICmpNE(var92, ConstantInt::get(i32, 0), "");
    builder.CreateCondBr(cond93, BB94, BB224);

    // 94:                                               ; preds = %91
    builder.SetInsertPoint(BB94);
    builder.CreateStore(ConstantInt::get(i32, 0), var4);
    builder.CreateBr(BB95);

    // 95:                                               ; preds = %180, %94
    builder.SetInsertPoint(BB95);
    Value *var96 = builder.CreateLoad(i32, var4, "");
    Value *cond97 = builder.CreateICmpSLT(var96, ConstantInt::get(i32, 200), "");
    builder.CreateCondBr(cond97, BB98, BB183);

    // 98:                                               ; preds = %95
    builder.SetInsertPoint(BB98);
    builder.CreateStore(ConstantInt::get(i32, 0), var5);
    builder.CreateBr(BB99);

    // 99:                                               ; preds = %176, %98
    builder.SetInsertPoint(BB99);
    Value *var100 = builder.CreateLoad(i32, var5, "");
    Value *cond101 = builder.CreateICmpSLT(var100, ConstantInt::get(i32, 200), "");
    builder.CreateCondBr(cond101, BB102, BB179);

    // 102:                                              ; preds = %99
    builder.SetInsertPoint(BB102);
    builder.CreateStore(ConstantInt::get(i32, 0), var6);
    builder.CreateStore(ConstantInt::get(i32, -1), var7);
    builder.CreateBr(BB103);

    // 103:                                              ; preds = %141, %102
    builder.SetInsertPoint(BB103);
    Value *var104 = builder.CreateLoad(i32, var7, "");
    Value *cond105 = builder.CreateICmpSLE(var104, ConstantInt::get(i32, 1), "");
    builder.CreateCondBr(cond105, BB106, BB144);

    // 106:                                              ; preds = %103
    builder.SetInsertPoint(BB106);
    builder.CreateStore(ConstantInt::get(i32, -1), var8);
    builder.CreateBr(BB107);

    // 107:                                              ; preds = %137, %106
    builder.SetInsertPoint(BB107);
    Value *var108 = builder.CreateLoad(i32, var8, "");
    Value *cond109 = builder.CreateICmpSLE(var108, ConstantInt::get(i32, 1), "");
    builder.CreateCondBr(cond109, BB110, BB140);

    // 110:                                              ; preds = %107
    builder.SetInsertPoint(BB110);
    Value *var111 = builder.CreateLoad(i32, var8, "");
    Value *cond112 = builder.CreateICmpEQ(var111, ConstantInt::get(i32, 0), "");
    builder.CreateCondBr(cond112, BB113, BB117);

    // 113:                                              ; preds = %110
    builder.SetInsertPoint(BB113);
    Value *var114 = builder.CreateLoad(i32, var7, "");
    Value *cond115 = builder.CreateICmpEQ(var114, ConstantInt::get(i32, 0), "");
    builder.CreateCondBr(cond115, BB116, BB117);

    // 116:                                              ; preds = %113
    builder.SetInsertPoint(BB116);
    builder.CreateBr(BB137);

    // 117:                                              ; preds = %113, %110
    builder.SetInsertPoint(BB117);
    Value *var118 = builder.CreateLoad(i32, var5, "");
    Value *var119 = builder.CreateLoad(i32, var8, "");
    Value *var120 = builder.CreateAdd(var118, var119, "");
    Value *var121 = builder.CreateAdd(var120, ConstantInt::get(i32, 200), "");
    Value *var122 = builder.CreateSRem(var121, ConstantInt::get(i32, 200), "");
    builder.CreateStore(var122, var9);

    Value *var123 = builder.CreateLoad(i32, var4, "");
    Value *var124 = builder.CreateLoad(i32, var7, "");
    Value *var125 = builder.CreateAdd(var123, var124, "");
    Value *var126 = builder.CreateAdd(var125, ConstantInt::get(i32, 200), "");
    Value *var127 = builder.CreateSRem(var126, ConstantInt::get(i32, 200), "");
    builder.CreateStore(var127, var10);

    Value *var128 = builder.CreateLoad(i32, var10, "");
    Value *var129 = builder.CreateMul(var128, ConstantInt::get(i32, 200), "");
    Value *var130 = builder.CreateLoad(i32, var9, "");
    Value *var131 = builder.CreateAdd(var129, var130, "");
    Value *var132 = builder.CreateSExt(var131, i64, "");

    Value *var133 = builder.CreateGEP(grid, {ConstantInt::get(i64, 0), var132});
    Value *var134 = builder.CreateLoad(i32, var133, "");
    Value *var135 = builder.CreateLoad(i32, var6, "");
    Value *var136 = builder.CreateAdd(var135, var134, "");
    builder.CreateStore(var136, var6);

    builder.CreateBr(BB137);

    // 137:                                              ; preds = %117, %116
    builder.SetInsertPoint(BB137);
    Value *var138 = builder.CreateLoad(i32, var8, "");
    Value *var139 = builder.CreateAdd(var138, ConstantInt::get(i32, 1), "");
    builder.CreateStore(var139, var8);
    builder.CreateBr(BB107);

    // 140:                                              ; preds = %107
    builder.SetInsertPoint(BB140);
    builder.CreateBr(BB141);

    // 141:                                              ; preds = %140
    builder.SetInsertPoint(BB141);
    Value *var142 = builder.CreateLoad(i32, var7, "");
    Value *var143 = builder.CreateAdd(var142, ConstantInt::get(i32, 1), "");
    builder.CreateStore(var143, var7);
    builder.CreateBr(BB103);

    // 144:                                              ; preds = %103
    builder.SetInsertPoint(BB144);
    Value *var145 = builder.CreateLoad(i32, var4, "");
    Value *var146 = builder.CreateMul(var145, ConstantInt::get(i32, 200), "");
    Value *var147 = builder.CreateLoad(i32, var5, "");
    Value *var148 = builder.CreateAdd(var146, var147, "");
    builder.CreateStore(var148, var11);

    Value *var149 = builder.CreateLoad(i32, var11, "");
    Value *var150 = builder.CreateSExt(var149, i64, "");
    Value *var151 = builder.CreateGEP(grid, {ConstantInt::get(i64, 0), var150});
    Value *var152 = builder.CreateLoad(i32, var151, "");
    Value *cond153 = builder.CreateICmpNE(var152, ConstantInt::get(i32, 0), "");
    builder.CreateCondBr(cond153, BB154, BB167);

    // 154:                                              ; preds = %144
    builder.SetInsertPoint(BB154);
    Value *var155 = builder.CreateLoad(i32, var6, "");
    Value *cond156 = builder.CreateICmpEQ(var155, ConstantInt::get(i32, 2), "");
    builder.CreateCondBr(cond156, BB160, BB157);

    // 157:                                              ; preds = %154
    builder.SetInsertPoint(BB157);
    Value *var158 = builder.CreateLoad(i32, var6, "");
    Value *cond159 = builder.CreateICmpEQ(var158, ConstantInt::get(i32, 3), "");
    builder.CreateBr(BB160);

    // 160:                                              ; preds = %157, %154
    builder.SetInsertPoint(BB160);
    PHINode *phi161 = builder.CreatePHI(Type::getInt1Ty(builder.getContext()), 2, "");
    phi161->addIncoming(ConstantInt::get(Type::getInt1Ty(builder.getContext()), true), BB154);
    phi161->addIncoming(cond159, BB157);
    Value *var162 = builder.CreateZExt(phi161, i64, "");
    Value *var163 = builder.CreateSelect(phi161, ConstantInt::get(i32, 1), ConstantInt::get(i32, 0), "");
    Value *var164 = builder.CreateLoad(i32, var11, "");
    Value *var165 = builder.CreateSExt(var164, i64, "");
    Value *var166 = builder.CreateGEP(new_grid, {ConstantInt::get(i64, 0), var165});
    builder.CreateStore(var163, var166);

    builder.CreateBr(BB175);

    // 167:                                              ; preds = %144
    builder.SetInsertPoint(BB167);
    Value *var168 = builder.CreateLoad(i32, var6, "");
    Value *cond169 = builder.CreateICmpEQ(var168, ConstantInt::get(i32, 3), "");
    Value *var170 = builder.CreateZExt(cond169, i64, "");
    Value *var171 = builder.CreateSelect(cond169, ConstantInt::get(i32, 1), ConstantInt::get(i32, 0), "");
    Value *var172 = builder.CreateLoad(i32, var11, "");
    Value *var173 = builder.CreateSExt(var172, i64, "");
    Value *var174 = builder.CreateGEP(new_grid, {ConstantInt::get(i64, 0), var173});
    builder.CreateStore(var171, var174);

    builder.CreateBr(BB175);

    // 175:                                              ; preds = %167, %160
    builder.SetInsertPoint(BB175);
    builder.CreateBr(BB176);

    // 176:                                              ; preds = %175
    builder.SetInsertPoint(BB176);
    Value *var177 = builder.CreateLoad(i32, var5, "");
    Value *var178 = builder.CreateAdd(var177, ConstantInt::get(i32, 1), "");
    builder.CreateStore(var178, var5);

    builder.CreateBr(BB99);

    // 179:                                              ; preds = %99
    builder.SetInsertPoint(BB179);
    builder.CreateBr(BB180);

    // 180:                                              ; preds = %179
    builder.SetInsertPoint(BB180);
    Value *var181 = builder.CreateLoad(i32, var4, "");
    Value *var182 = builder.CreateAdd(var181, ConstantInt::get(i32, 1), "");
    builder.CreateStore(var182, var4);

    builder.CreateBr(BB95);

    // 183:                                              ; preds = %95
    builder.SetInsertPoint(BB183);
    builder.CreateStore(ConstantInt::get(i32, 0), var12);
    builder.CreateBr(BB184);

    // 184:                                              ; preds = %195, %183
    builder.SetInsertPoint(BB184);
    Value *var185 = builder.CreateLoad(i32, var12, "");
    Value *cond186 = builder.CreateICmpSLT(var185, ConstantInt::get(i32, 40000), "");
    builder.CreateCondBr(cond186, BB187, BB198);

    // 187:                                              ; preds = %184
    builder.SetInsertPoint(BB187);
    Value *var188 = builder.CreateLoad(i32, var12, "");
    Value *var189 = builder.CreateSExt(var188, i64, "");
    Value *var190 = builder.CreateGEP(new_grid, {ConstantInt::get(i64, 0), var189});
    Value *var191 = builder.CreateLoad(i32, var190, "");
    Value *var192 = builder.CreateLoad(i32, var12, "");
    Value *var193 = builder.CreateSExt(var192, i64, "");
    Value *var194 = builder.CreateGEP(grid, {ConstantInt::get(i64, 0), var193});
    builder.CreateStore(var191, var194);
    builder.CreateBr(BB195);

    // 195:                                              ; preds = %187
    builder.SetInsertPoint(BB195);
    Value *var196 = builder.CreateLoad(i32, var12, "");
    Value *var197 = builder.CreateAdd(var196, ConstantInt::get(i32, 1), "");
    builder.CreateStore(var197, var12);
    builder.CreateBr(BB184);

    // 198:                                              ; preds = %184
    builder.SetInsertPoint(BB198);
    builder.CreateStore(ConstantInt::get(i32, 0), var13);
    builder.CreateBr(BB199);

    // 199:                                              ; preds = %220, %198
    builder.SetInsertPoint(BB199);
    Value *var200 = builder.CreateLoad(i32, var13, "");
    Value *cond201 = builder.CreateICmpSLT(var200, ConstantInt::get(i32, 200), "");
    builder.CreateCondBr(cond201, BB202, BB223);

    // 202:                                              ; preds = %199
    builder.SetInsertPoint(BB202);
    builder.CreateStore(ConstantInt::get(i32, 0), var14);
    builder.CreateBr(BB203);

    // 203:                                              ; preds = %216, %202
    builder.SetInsertPoint(BB203);
    Value *var204 = builder.CreateLoad(i32, var14, "");
    Value *cond205 = builder.CreateICmpSLT(var204, ConstantInt::get(i32, 200), "");
    builder.CreateCondBr(cond205, BB206, BB219);

    // 206:                                              ; preds = %203
    builder.SetInsertPoint(BB206);
    Value *var207 = builder.CreateLoad(i32, var14, "");
    Value *var208 = builder.CreateLoad(i32, var13, "");
    Value *var209 = builder.CreateLoad(i32, var13, "");
    Value *var210 = builder.CreateMul(var209, ConstantInt::get(i32, 200), "");
    Value *var211 = builder.CreateLoad(i32, var14, "");
    Value *var212 = builder.CreateAdd(var210, var211, "");
    Value *var213 = builder.CreateSExt(var212, i64, "");
    Value *var214 = builder.CreateGEP(grid, {ConstantInt::get(i64, 0), var213});
    Value *var215 = builder.CreateLoad(i32, var214, "");
    Value *args[] = {var207, var208, var215};
    builder.CreateCall(simPutPixelFunc, args);
    builder.CreateBr(BB216);

    // 216:                                              ; preds = %206
    builder.SetInsertPoint(BB216);
    Value *var217 = builder.CreateLoad(i32, var14, "");
    Value *var218 = builder.CreateAdd(var217, ConstantInt::get(i32, 1), "");
    builder.CreateStore(var218, var14);
    builder.CreateBr(BB203);

    // 219:                                              ; preds = %203
    builder.SetInsertPoint(BB219);
    builder.CreateBr(BB220);

    // 220:                                              ; preds = %219
    builder.SetInsertPoint(BB220);
    Value *var221 = builder.CreateLoad(i32, var13, "");
    Value *var222 = builder.CreateAdd(var221, ConstantInt::get(i32, 1), "");
    builder.CreateStore(var222, var13);
    builder.CreateBr(BB199);

    // 223:                                              ; preds = %199
    builder.SetInsertPoint(BB223);
    builder.CreateCall(simFlushFunc);
    builder.CreateBr(BB91);

    // 224:                                              ; preds = %91
    builder.SetInsertPoint(BB224);
    builder.CreateRetVoid();

    // Dump LLVM IR
    module->print(outs(), nullptr);
    outs() << "\n";
    bool verif = verifyFunction(*appFunc, &outs());
    outs() << "[VERIFICATION] " << (!verif ? "OK\n\n" : "FAIL\n\n");

    // LLVM IR Interpreter
    outs() << "[EE] Run\n";
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
    ee->InstallLazyFunctionCreator([=](const std::string &fnName) -> void *
    {
        if (fnName == "put_pixel") {
        return reinterpret_cast<void *>(put_pixel);
        }
        if (fnName == "flush") {
        return reinterpret_cast<void *>(flush);
        }

        return nullptr; 
    });
    
    
    ee->finalizeObject();

    sim_init();

    ArrayRef<GenericValue> noargs;
    GenericValue v = ee->runFunction(appFunc, noargs);
    outs() << "[EE] Result: " << v.IntVal << "\n";

    sim_exit();
    return EXIT_SUCCESS;
}
