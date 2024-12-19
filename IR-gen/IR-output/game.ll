; ModuleID = 'app.c'
source_filename = "app.c"

@grid = internal addrspace(16) global [40000 x i32] zeroinitializer
@new_grid = internal addrspace(16) global [40000 x i32] zeroinitializer

declare void @put_pixel(i32, i32, i32)

declare void @flush()

define void @app() {
  %1 = alloca i32
  %2 = alloca i32
  %3 = alloca i32
  %4 = alloca i32
  %5 = alloca i32
  %6 = alloca i32
  %7 = alloca i32
  %8 = alloca i32
  %9 = alloca i32
  %10 = alloca i32
  %11 = alloca i32
  %12 = alloca i32
  %13 = alloca i32
  %14 = alloca i32
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1600)
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1601)
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1602)
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1403)
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1202)
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1005)
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1206)
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1404)
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1405)
  store i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 1406)
  store i32 0, i32* %1
  br label %15

15:                                               ; preds = %87, %0
  %16 = load i32, i32* %1
  %17 = icmp slt i32 %16, 13
  br i1 %17, label %18, label %90

18:                                               ; preds = %15
  store i32 0, i32* %2
  br label %19

19:                                               ; preds = %83, %18
  %20 = load i32, i32* %2
  %21 = icmp slt i32 %20, 13
  br i1 %21, label %22, label %86

22:                                               ; preds = %19
  %23 = load i32, i32* %1
  %24 = icmp eq i32 %23, 0
  br i1 %24, label %31, label %25

25:                                               ; preds = %22
  %26 = load i32, i32* %1
  %27 = icmp eq i32 %26, 6
  br i1 %27, label %31, label %28

28:                                               ; preds = %25
  %29 = load i32, i32* %1
  %30 = icmp eq i32 %29, 12
  br i1 %30, label %31, label %52

31:                                               ; preds = %28, %25, %22
  %32 = load i32, i32* %2
  %33 = icmp sgt i32 %32, 0
  br i1 %33, label %34, label %37

34:                                               ; preds = %31
  %35 = load i32, i32* %2
  %36 = icmp slt i32 %35, 6
  br i1 %36, label %43, label %37

37:                                               ; preds = %34, %31
  %38 = load i32, i32* %2
  %39 = icmp sgt i32 %38, 7
  br i1 %39, label %40, label %52

40:                                               ; preds = %37
  %41 = load i32, i32* %2
  %42 = icmp slt i32 %41, 13
  br i1 %42, label %43, label %52

43:                                               ; preds = %40, %34
  %44 = load i32, i32* %1
  %45 = add i32 %44, 50
  %46 = mul i32 %45, 200
  %47 = load i32, i32* %2
  %48 = add i32 %47, 50
  %49 = add i32 %46, %48
  %50 = sext i32 %49 to i64
  %51 = getelementptr [40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 %50
  store i32 1, i32 addrspace(16)* %51
  br label %52

52:                                               ; preds = %43, %40, %37, %28
  %53 = load i32, i32* %2
  %54 = icmp eq i32 %53, 0
  br i1 %54, label %61, label %55

55:                                               ; preds = %52
  %56 = load i32, i32* %2
  %57 = icmp eq i32 %56, 6
  br i1 %57, label %61, label %58

58:                                               ; preds = %55
  %59 = load i32, i32* %2
  %60 = icmp eq i32 %59, 12
  br i1 %60, label %61, label %82

61:                                               ; preds = %58, %55, %52
  %62 = load i32, i32* %1
  %63 = icmp sgt i32 %62, 0
  br i1 %63, label %64, label %67

64:                                               ; preds = %61
  %65 = load i32, i32* %1
  %66 = icmp slt i32 %65, 6
  br i1 %66, label %73, label %67

67:                                               ; preds = %64, %61
  %68 = load i32, i32* %1
  %69 = icmp sgt i32 %68, 7
  br i1 %69, label %70, label %82

70:                                               ; preds = %67
  %71 = load i32, i32* %1
  %72 = icmp slt i32 %71, 13
  br i1 %72, label %73, label %82

73:                                               ; preds = %70, %64
  %74 = load i32, i32* %1
  %75 = add i32 %74, 50
  %76 = mul i32 %75, 200
  %77 = load i32, i32* %2
  %78 = add i32 %77, 50
  %79 = add i32 %76, %78
  %80 = sext i32 %79 to i64
  %81 = getelementptr [40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 %80
  store i32 1, i32 addrspace(16)* %81
  br label %82

82:                                               ; preds = %73, %70, %67, %58
  br label %83

83:                                               ; preds = %82
  %84 = load i32, i32* %2
  %85 = add i32 %84, 1
  store i32 %85, i32* %2
  br label %19

86:                                               ; preds = %19
  br label %87

87:                                               ; preds = %86
  %88 = load i32, i32* %1
  %89 = add i32 %88, 1
  store i32 %89, i32* %1
  br label %15

90:                                               ; preds = %15
  store volatile i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 8040)
  store volatile i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 8041)
  store volatile i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 8239)
  store volatile i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 8242)
  store volatile i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 8440)
  store volatile i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 8441)
  store volatile i32 1, i32 addrspace(16)* getelementptr inbounds ([40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 8641)
  store i32 1, i32* %3
  br label %91

91:                                               ; preds = %223, %90
  %92 = load i32, i32* %3
  %93 = icmp ne i32 %92, 0
  br i1 %93, label %94, label %224

94:                                               ; preds = %91
  store i32 0, i32* %4
  br label %95

95:                                               ; preds = %180, %94
  %96 = load i32, i32* %4
  %97 = icmp slt i32 %96, 200
  br i1 %97, label %98, label %183

98:                                               ; preds = %95
  store i32 0, i32* %5
  br label %99

99:                                               ; preds = %176, %98
  %100 = load i32, i32* %5
  %101 = icmp slt i32 %100, 200
  br i1 %101, label %102, label %179

102:                                              ; preds = %99
  store i32 0, i32* %6
  store i32 -1, i32* %7
  br label %103

103:                                              ; preds = %141, %102
  %104 = load i32, i32* %7
  %105 = icmp sle i32 %104, 1
  br i1 %105, label %106, label %144

106:                                              ; preds = %103
  store i32 -1, i32* %8
  br label %107

107:                                              ; preds = %137, %106
  %108 = load i32, i32* %8
  %109 = icmp sle i32 %108, 1
  br i1 %109, label %110, label %140

110:                                              ; preds = %107
  %111 = load i32, i32* %8
  %112 = icmp eq i32 %111, 0
  br i1 %112, label %113, label %117

113:                                              ; preds = %110
  %114 = load i32, i32* %7
  %115 = icmp eq i32 %114, 0
  br i1 %115, label %116, label %117

116:                                              ; preds = %113
  br label %137

117:                                              ; preds = %113, %110
  %118 = load i32, i32* %5
  %119 = load i32, i32* %8
  %120 = add i32 %118, %119
  %121 = add i32 %120, 200
  %122 = srem i32 %121, 200
  store i32 %122, i32* %9
  %123 = load i32, i32* %4
  %124 = load i32, i32* %7
  %125 = add i32 %123, %124
  %126 = add i32 %125, 200
  %127 = srem i32 %126, 200
  store i32 %127, i32* %10
  %128 = load i32, i32* %10
  %129 = mul i32 %128, 200
  %130 = load i32, i32* %9
  %131 = add i32 %129, %130
  %132 = sext i32 %131 to i64
  %133 = getelementptr [40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 %132
  %134 = load i32, i32 addrspace(16)* %133
  %135 = load i32, i32* %6
  %136 = add i32 %135, %134
  store i32 %136, i32* %6
  br label %137

137:                                              ; preds = %117, %116
  %138 = load i32, i32* %8
  %139 = add i32 %138, 1
  store i32 %139, i32* %8
  br label %107

140:                                              ; preds = %107
  br label %141

141:                                              ; preds = %140
  %142 = load i32, i32* %7
  %143 = add i32 %142, 1
  store i32 %143, i32* %7
  br label %103

144:                                              ; preds = %103
  %145 = load i32, i32* %4
  %146 = mul i32 %145, 200
  %147 = load i32, i32* %5
  %148 = add i32 %146, %147
  store i32 %148, i32* %11
  %149 = load i32, i32* %11
  %150 = sext i32 %149 to i64
  %151 = getelementptr [40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 %150
  %152 = load i32, i32 addrspace(16)* %151
  %153 = icmp ne i32 %152, 0
  br i1 %153, label %154, label %167

154:                                              ; preds = %144
  %155 = load i32, i32* %6
  %156 = icmp eq i32 %155, 2
  br i1 %156, label %160, label %157

157:                                              ; preds = %154
  %158 = load i32, i32* %6
  %159 = icmp eq i32 %158, 3
  br label %160

160:                                              ; preds = %157, %154
  %161 = phi i1 [ true, %154 ], [ %159, %157 ]
  %162 = zext i1 %161 to i64
  %163 = select i1 %161, i32 1, i32 0
  %164 = load i32, i32* %11
  %165 = sext i32 %164 to i64
  %166 = getelementptr [40000 x i32], [40000 x i32] addrspace(16)* @new_grid, i64 0, i64 %165
  store i32 %163, i32 addrspace(16)* %166
  br label %175

167:                                              ; preds = %144
  %168 = load i32, i32* %6
  %169 = icmp eq i32 %168, 3
  %170 = zext i1 %169 to i64
  %171 = select i1 %169, i32 1, i32 0
  %172 = load i32, i32* %11
  %173 = sext i32 %172 to i64
  %174 = getelementptr [40000 x i32], [40000 x i32] addrspace(16)* @new_grid, i64 0, i64 %173
  store i32 %171, i32 addrspace(16)* %174
  br label %175

175:                                              ; preds = %167, %160
  br label %176

176:                                              ; preds = %175
  %177 = load i32, i32* %5
  %178 = add i32 %177, 1
  store i32 %178, i32* %5
  br label %99

179:                                              ; preds = %99
  br label %180

180:                                              ; preds = %179
  %181 = load i32, i32* %4
  %182 = add i32 %181, 1
  store i32 %182, i32* %4
  br label %95

183:                                              ; preds = %95
  store i32 0, i32* %12
  br label %184

184:                                              ; preds = %195, %183
  %185 = load i32, i32* %12
  %186 = icmp slt i32 %185, 40000
  br i1 %186, label %187, label %198

187:                                              ; preds = %184
  %188 = load i32, i32* %12
  %189 = sext i32 %188 to i64
  %190 = getelementptr [40000 x i32], [40000 x i32] addrspace(16)* @new_grid, i64 0, i64 %189
  %191 = load i32, i32 addrspace(16)* %190
  %192 = load i32, i32* %12
  %193 = sext i32 %192 to i64
  %194 = getelementptr [40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 %193
  store i32 %191, i32 addrspace(16)* %194
  br label %195

195:                                              ; preds = %187
  %196 = load i32, i32* %12
  %197 = add i32 %196, 1
  store i32 %197, i32* %12
  br label %184

198:                                              ; preds = %184
  store i32 0, i32* %13
  br label %199

199:                                              ; preds = %220, %198
  %200 = load i32, i32* %13
  %201 = icmp slt i32 %200, 200
  br i1 %201, label %202, label %223

202:                                              ; preds = %199
  store i32 0, i32* %14
  br label %203

203:                                              ; preds = %216, %202
  %204 = load i32, i32* %14
  %205 = icmp slt i32 %204, 200
  br i1 %205, label %206, label %219

206:                                              ; preds = %203
  %207 = load i32, i32* %14
  %208 = load i32, i32* %13
  %209 = load i32, i32* %13
  %210 = mul i32 %209, 200
  %211 = load i32, i32* %14
  %212 = add i32 %210, %211
  %213 = sext i32 %212 to i64
  %214 = getelementptr [40000 x i32], [40000 x i32] addrspace(16)* @grid, i64 0, i64 %213
  %215 = load i32, i32 addrspace(16)* %214
  call void @put_pixel(i32 %207, i32 %208, i32 %215)
  br label %216

216:                                              ; preds = %206
  %217 = load i32, i32* %14
  %218 = add i32 %217, 1
  store i32 %218, i32* %14
  br label %203

219:                                              ; preds = %203
  br label %220

220:                                              ; preds = %219
  %221 = load i32, i32* %13
  %222 = add i32 %221, 1
  store i32 %222, i32* %13
  br label %199

223:                                              ; preds = %199
  call void @flush()
  br label %91

224:                                              ; preds = %91
  ret void
}
