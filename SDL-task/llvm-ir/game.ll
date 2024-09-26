; ModuleID = 'game.c'
source_filename = "game.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@grid = internal global [480000 x i32] zeroinitializer, align 16
@new_grid = internal global [480000 x i32] zeroinitializer, align 16

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @count_neighbors(i32 %0, i32 %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32 %1, i32* %4, align 4
  store i32 0, i32* %5, align 4
  store i32 -1, i32* %6, align 4
  br label %10

10:                                               ; preds = %48, %2
  %11 = load i32, i32* %6, align 4
  %12 = icmp sle i32 %11, 1
  br i1 %12, label %13, label %51

13:                                               ; preds = %10
  store i32 -1, i32* %7, align 4
  br label %14

14:                                               ; preds = %44, %13
  %15 = load i32, i32* %7, align 4
  %16 = icmp sle i32 %15, 1
  br i1 %16, label %17, label %47

17:                                               ; preds = %14
  %18 = load i32, i32* %7, align 4
  %19 = icmp eq i32 %18, 0
  br i1 %19, label %20, label %24

20:                                               ; preds = %17
  %21 = load i32, i32* %6, align 4
  %22 = icmp eq i32 %21, 0
  br i1 %22, label %23, label %24

23:                                               ; preds = %20
  br label %44

24:                                               ; preds = %20, %17
  %25 = load i32, i32* %3, align 4
  %26 = load i32, i32* %7, align 4
  %27 = add nsw i32 %25, %26
  %28 = add nsw i32 %27, 800
  %29 = srem i32 %28, 800
  store i32 %29, i32* %8, align 4
  %30 = load i32, i32* %4, align 4
  %31 = load i32, i32* %6, align 4
  %32 = add nsw i32 %30, %31
  %33 = add nsw i32 %32, 600
  %34 = srem i32 %33, 600
  store i32 %34, i32* %9, align 4
  %35 = load i32, i32* %9, align 4
  %36 = mul nsw i32 %35, 800
  %37 = load i32, i32* %8, align 4
  %38 = add nsw i32 %36, %37
  %39 = sext i32 %38 to i64
  %40 = getelementptr inbounds [480000 x i32], [480000 x i32]* @grid, i64 0, i64 %39
  %41 = load i32, i32* %40, align 4
  %42 = load i32, i32* %5, align 4
  %43 = add nsw i32 %42, %41
  store i32 %43, i32* %5, align 4
  br label %44

44:                                               ; preds = %24, %23
  %45 = load i32, i32* %7, align 4
  %46 = add nsw i32 %45, 1
  store i32 %46, i32* %7, align 4
  br label %14

47:                                               ; preds = %14
  br label %48

48:                                               ; preds = %47
  %49 = load i32, i32* %6, align 4
  %50 = add nsw i32 %49, 1
  store i32 %50, i32* %6, align 4
  br label %10

51:                                               ; preds = %10
  %52 = load i32, i32* %5, align 4
  ret i32 %52
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @update_grid() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  br label %6

6:                                                ; preds = %52, %0
  %7 = load i32, i32* %1, align 4
  %8 = icmp slt i32 %7, 600
  br i1 %8, label %9, label %55

9:                                                ; preds = %6
  store i32 0, i32* %2, align 4
  br label %10

10:                                               ; preds = %48, %9
  %11 = load i32, i32* %2, align 4
  %12 = icmp slt i32 %11, 800
  br i1 %12, label %13, label %51

13:                                               ; preds = %10
  %14 = load i32, i32* %2, align 4
  %15 = load i32, i32* %1, align 4
  %16 = call i32 @count_neighbors(i32 %14, i32 %15)
  store i32 %16, i32* %3, align 4
  %17 = load i32, i32* %1, align 4
  %18 = mul nsw i32 %17, 800
  %19 = load i32, i32* %2, align 4
  %20 = add nsw i32 %18, %19
  store i32 %20, i32* %4, align 4
  %21 = load i32, i32* %4, align 4
  %22 = sext i32 %21 to i64
  %23 = getelementptr inbounds [480000 x i32], [480000 x i32]* @grid, i64 0, i64 %22
  %24 = load i32, i32* %23, align 4
  %25 = icmp ne i32 %24, 0
  br i1 %25, label %26, label %39

26:                                               ; preds = %13
  %27 = load i32, i32* %3, align 4
  %28 = icmp eq i32 %27, 2
  br i1 %28, label %32, label %29

29:                                               ; preds = %26
  %30 = load i32, i32* %3, align 4
  %31 = icmp eq i32 %30, 3
  br label %32

32:                                               ; preds = %29, %26
  %33 = phi i1 [ true, %26 ], [ %31, %29 ]
  %34 = zext i1 %33 to i64
  %35 = select i1 %33, i32 1, i32 0
  %36 = load i32, i32* %4, align 4
  %37 = sext i32 %36 to i64
  %38 = getelementptr inbounds [480000 x i32], [480000 x i32]* @new_grid, i64 0, i64 %37
  store i32 %35, i32* %38, align 4
  br label %47

39:                                               ; preds = %13
  %40 = load i32, i32* %3, align 4
  %41 = icmp eq i32 %40, 3
  %42 = zext i1 %41 to i64
  %43 = select i1 %41, i32 1, i32 0
  %44 = load i32, i32* %4, align 4
  %45 = sext i32 %44 to i64
  %46 = getelementptr inbounds [480000 x i32], [480000 x i32]* @new_grid, i64 0, i64 %45
  store i32 %43, i32* %46, align 4
  br label %47

47:                                               ; preds = %39, %32
  br label %48

48:                                               ; preds = %47
  %49 = load i32, i32* %2, align 4
  %50 = add nsw i32 %49, 1
  store i32 %50, i32* %2, align 4
  br label %10

51:                                               ; preds = %10
  br label %52

52:                                               ; preds = %51
  %53 = load i32, i32* %1, align 4
  %54 = add nsw i32 %53, 1
  store i32 %54, i32* %1, align 4
  br label %6

55:                                               ; preds = %6
  store i32 0, i32* %5, align 4
  br label %56

56:                                               ; preds = %67, %55
  %57 = load i32, i32* %5, align 4
  %58 = icmp slt i32 %57, 480000
  br i1 %58, label %59, label %70

59:                                               ; preds = %56
  %60 = load i32, i32* %5, align 4
  %61 = sext i32 %60 to i64
  %62 = getelementptr inbounds [480000 x i32], [480000 x i32]* @new_grid, i64 0, i64 %61
  %63 = load i32, i32* %62, align 4
  %64 = load i32, i32* %5, align 4
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds [480000 x i32], [480000 x i32]* @grid, i64 0, i64 %65
  store i32 %63, i32* %66, align 4
  br label %67

67:                                               ; preds = %59
  %68 = load i32, i32* %5, align 4
  %69 = add nsw i32 %68, 1
  store i32 %69, i32* %5, align 4
  br label %56

70:                                               ; preds = %56
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @init_grid() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  br label %2

2:                                                ; preds = %11, %0
  %3 = load i32, i32* %1, align 4
  %4 = icmp slt i32 %3, 480000
  br i1 %4, label %5, label %14

5:                                                ; preds = %2
  %6 = call i32 @rand() #3
  %7 = srem i32 %6, 2
  %8 = load i32, i32* %1, align 4
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds [480000 x i32], [480000 x i32]* @grid, i64 0, i64 %9
  store i32 %7, i32* %10, align 4
  br label %11

11:                                               ; preds = %5
  %12 = load i32, i32* %1, align 4
  %13 = add nsw i32 %12, 1
  store i32 %13, i32* %1, align 4
  br label %2

14:                                               ; preds = %2
  ret void
}

; Function Attrs: nounwind
declare dso_local i32 @rand() #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @app() #0 {
  %1 = alloca i8, align 1
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  call void @init_grid()
  store i8 1, i8* %1, align 1
  br label %4

4:                                                ; preds = %32, %0
  %5 = load i8, i8* %1, align 1
  %6 = trunc i8 %5 to i1
  br i1 %6, label %7, label %33

7:                                                ; preds = %4
  call void @update_grid()
  store i32 0, i32* %2, align 4
  br label %8

8:                                                ; preds = %29, %7
  %9 = load i32, i32* %2, align 4
  %10 = icmp slt i32 %9, 600
  br i1 %10, label %11, label %32

11:                                               ; preds = %8
  store i32 0, i32* %3, align 4
  br label %12

12:                                               ; preds = %25, %11
  %13 = load i32, i32* %3, align 4
  %14 = icmp slt i32 %13, 800
  br i1 %14, label %15, label %28

15:                                               ; preds = %12
  %16 = load i32, i32* %3, align 4
  %17 = load i32, i32* %2, align 4
  %18 = load i32, i32* %2, align 4
  %19 = mul nsw i32 %18, 800
  %20 = load i32, i32* %3, align 4
  %21 = add nsw i32 %19, %20
  %22 = sext i32 %21 to i64
  %23 = getelementptr inbounds [480000 x i32], [480000 x i32]* @grid, i64 0, i64 %22
  %24 = load i32, i32* %23, align 4
  call void @put_pixel(i32 %16, i32 %17, i32 %24)
  br label %25

25:                                               ; preds = %15
  %26 = load i32, i32* %3, align 4
  %27 = add nsw i32 %26, 1
  store i32 %27, i32* %3, align 4
  br label %12

28:                                               ; preds = %12
  br label %29

29:                                               ; preds = %28
  %30 = load i32, i32* %2, align 4
  %31 = add nsw i32 %30, 1
  store i32 %31, i32* %2, align 4
  br label %8

32:                                               ; preds = %8
  call void (...) @flush()
  br label %4

33:                                               ; preds = %4
  ret void
}

declare dso_local void @put_pixel(i32, i32, i32) #2

declare dso_local void @flush(...) #2

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
