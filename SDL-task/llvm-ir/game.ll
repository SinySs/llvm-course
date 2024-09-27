; ModuleID = 'game.c'
source_filename = "game.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @swap_arrays(i32** %0, i32** %1) #0 {
  %3 = alloca i32**, align 8
  %4 = alloca i32**, align 8
  %5 = alloca i32*, align 8
  store i32** %0, i32*** %3, align 8
  store i32** %1, i32*** %4, align 8
  %6 = load i32**, i32*** %3, align 8
  %7 = load i32*, i32** %6, align 8
  store i32* %7, i32** %5, align 8
  %8 = load i32**, i32*** %4, align 8
  %9 = load i32*, i32** %8, align 8
  %10 = load i32**, i32*** %3, align 8
  store i32* %9, i32** %10, align 8
  %11 = load i32*, i32** %5, align 8
  %12 = load i32**, i32*** %4, align 8
  store i32* %11, i32** %12, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @count_neighbors(i32 %0, i32 %1, i32* %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32*, align 8
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  store i32 %0, i32* %4, align 4
  store i32 %1, i32* %5, align 4
  store i32* %2, i32** %6, align 8
  store i32 0, i32* %7, align 4
  store i32 -1, i32* %8, align 4
  br label %12

12:                                               ; preds = %51, %3
  %13 = load i32, i32* %8, align 4
  %14 = icmp sle i32 %13, 1
  br i1 %14, label %15, label %54

15:                                               ; preds = %12
  store i32 -1, i32* %9, align 4
  br label %16

16:                                               ; preds = %47, %15
  %17 = load i32, i32* %9, align 4
  %18 = icmp sle i32 %17, 1
  br i1 %18, label %19, label %50

19:                                               ; preds = %16
  %20 = load i32, i32* %9, align 4
  %21 = icmp eq i32 %20, 0
  br i1 %21, label %22, label %26

22:                                               ; preds = %19
  %23 = load i32, i32* %8, align 4
  %24 = icmp eq i32 %23, 0
  br i1 %24, label %25, label %26

25:                                               ; preds = %22
  br label %47

26:                                               ; preds = %22, %19
  %27 = load i32, i32* %4, align 4
  %28 = load i32, i32* %9, align 4
  %29 = add nsw i32 %27, %28
  %30 = add nsw i32 %29, 800
  %31 = srem i32 %30, 800
  store i32 %31, i32* %10, align 4
  %32 = load i32, i32* %5, align 4
  %33 = load i32, i32* %8, align 4
  %34 = add nsw i32 %32, %33
  %35 = add nsw i32 %34, 600
  %36 = srem i32 %35, 600
  store i32 %36, i32* %11, align 4
  %37 = load i32*, i32** %6, align 8
  %38 = load i32, i32* %11, align 4
  %39 = mul nsw i32 %38, 800
  %40 = load i32, i32* %10, align 4
  %41 = add nsw i32 %39, %40
  %42 = sext i32 %41 to i64
  %43 = getelementptr inbounds i32, i32* %37, i64 %42
  %44 = load i32, i32* %43, align 4
  %45 = load i32, i32* %7, align 4
  %46 = add nsw i32 %45, %44
  store i32 %46, i32* %7, align 4
  br label %47

47:                                               ; preds = %26, %25
  %48 = load i32, i32* %9, align 4
  %49 = add nsw i32 %48, 1
  store i32 %49, i32* %9, align 4
  br label %16

50:                                               ; preds = %16
  br label %51

51:                                               ; preds = %50
  %52 = load i32, i32* %8, align 4
  %53 = add nsw i32 %52, 1
  store i32 %53, i32* %8, align 4
  br label %12

54:                                               ; preds = %12
  %55 = load i32, i32* %7, align 4
  ret i32 %55
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @update_grid(i32** %0, i32** %1) #0 {
  %3 = alloca i32**, align 8
  %4 = alloca i32**, align 8
  %5 = alloca i32*, align 8
  %6 = alloca i32*, align 8
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  store i32** %0, i32*** %3, align 8
  store i32** %1, i32*** %4, align 8
  %11 = load i32**, i32*** %3, align 8
  %12 = load i32*, i32** %11, align 8
  store i32* %12, i32** %5, align 8
  %13 = load i32**, i32*** %4, align 8
  %14 = load i32*, i32** %13, align 8
  store i32* %14, i32** %6, align 8
  store i32 0, i32* %7, align 4
  br label %15

15:                                               ; preds = %65, %2
  %16 = load i32, i32* %7, align 4
  %17 = icmp slt i32 %16, 600
  br i1 %17, label %18, label %68

18:                                               ; preds = %15
  store i32 0, i32* %8, align 4
  br label %19

19:                                               ; preds = %61, %18
  %20 = load i32, i32* %8, align 4
  %21 = icmp slt i32 %20, 800
  br i1 %21, label %22, label %64

22:                                               ; preds = %19
  %23 = load i32, i32* %8, align 4
  %24 = load i32, i32* %7, align 4
  %25 = load i32*, i32** %5, align 8
  %26 = call i32 @count_neighbors(i32 %23, i32 %24, i32* %25)
  store i32 %26, i32* %9, align 4
  %27 = load i32, i32* %7, align 4
  %28 = mul nsw i32 %27, 800
  %29 = load i32, i32* %8, align 4
  %30 = add nsw i32 %28, %29
  store i32 %30, i32* %10, align 4
  %31 = load i32*, i32** %5, align 8
  %32 = load i32, i32* %10, align 4
  %33 = sext i32 %32 to i64
  %34 = getelementptr inbounds i32, i32* %31, i64 %33
  %35 = load i32, i32* %34, align 4
  %36 = icmp ne i32 %35, 0
  br i1 %36, label %37, label %51

37:                                               ; preds = %22
  %38 = load i32, i32* %9, align 4
  %39 = icmp eq i32 %38, 2
  br i1 %39, label %43, label %40

40:                                               ; preds = %37
  %41 = load i32, i32* %9, align 4
  %42 = icmp eq i32 %41, 3
  br label %43

43:                                               ; preds = %40, %37
  %44 = phi i1 [ true, %37 ], [ %42, %40 ]
  %45 = zext i1 %44 to i64
  %46 = select i1 %44, i32 1, i32 0
  %47 = load i32*, i32** %6, align 8
  %48 = load i32, i32* %10, align 4
  %49 = sext i32 %48 to i64
  %50 = getelementptr inbounds i32, i32* %47, i64 %49
  store i32 %46, i32* %50, align 4
  br label %60

51:                                               ; preds = %22
  %52 = load i32, i32* %9, align 4
  %53 = icmp eq i32 %52, 3
  %54 = zext i1 %53 to i64
  %55 = select i1 %53, i32 1, i32 0
  %56 = load i32*, i32** %6, align 8
  %57 = load i32, i32* %10, align 4
  %58 = sext i32 %57 to i64
  %59 = getelementptr inbounds i32, i32* %56, i64 %58
  store i32 %55, i32* %59, align 4
  br label %60

60:                                               ; preds = %51, %43
  br label %61

61:                                               ; preds = %60
  %62 = load i32, i32* %8, align 4
  %63 = add nsw i32 %62, 1
  store i32 %63, i32* %8, align 4
  br label %19

64:                                               ; preds = %19
  br label %65

65:                                               ; preds = %64
  %66 = load i32, i32* %7, align 4
  %67 = add nsw i32 %66, 1
  store i32 %67, i32* %7, align 4
  br label %15

68:                                               ; preds = %15
  %69 = load i32**, i32*** %3, align 8
  %70 = load i32**, i32*** %4, align 8
  call void @swap_arrays(i32** %69, i32** %70)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @init_grid(i32* %0) #0 {
  %2 = alloca i32*, align 8
  %3 = alloca i32, align 4
  store i32* %0, i32** %2, align 8
  store i32 0, i32* %3, align 4
  br label %4

4:                                                ; preds = %14, %1
  %5 = load i32, i32* %3, align 4
  %6 = icmp slt i32 %5, 480000
  br i1 %6, label %7, label %17

7:                                                ; preds = %4
  %8 = call i32 (...) @sim_rand()
  %9 = srem i32 %8, 2
  %10 = load i32*, i32** %2, align 8
  %11 = load i32, i32* %3, align 4
  %12 = sext i32 %11 to i64
  %13 = getelementptr inbounds i32, i32* %10, i64 %12
  store i32 %9, i32* %13, align 4
  br label %14

14:                                               ; preds = %7
  %15 = load i32, i32* %3, align 4
  %16 = add nsw i32 %15, 1
  store i32 %16, i32* %3, align 4
  br label %4

17:                                               ; preds = %4
  ret void
}

declare dso_local i32 @sim_rand(...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @app() #0 {
  %1 = alloca [480000 x i32], align 16
  %2 = alloca [480000 x i32], align 16
  %3 = alloca i32*, align 8
  %4 = alloca i32*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = getelementptr inbounds [480000 x i32], [480000 x i32]* %1, i64 0, i64 0
  store i32* %8, i32** %3, align 8
  %9 = getelementptr inbounds [480000 x i32], [480000 x i32]* %2, i64 0, i64 0
  store i32* %9, i32** %4, align 8
  %10 = getelementptr inbounds [480000 x i32], [480000 x i32]* %1, i64 0, i64 0
  call void @init_grid(i32* %10)
  store i32 1, i32* %5, align 4
  br label %11

11:                                               ; preds = %39, %0
  %12 = load i32, i32* %5, align 4
  %13 = icmp ne i32 %12, 0
  br i1 %13, label %14, label %40

14:                                               ; preds = %11
  call void @update_grid(i32** %3, i32** %4)
  store i32 0, i32* %6, align 4
  br label %15

15:                                               ; preds = %36, %14
  %16 = load i32, i32* %6, align 4
  %17 = icmp slt i32 %16, 600
  br i1 %17, label %18, label %39

18:                                               ; preds = %15
  store i32 0, i32* %7, align 4
  br label %19

19:                                               ; preds = %32, %18
  %20 = load i32, i32* %7, align 4
  %21 = icmp slt i32 %20, 800
  br i1 %21, label %22, label %35

22:                                               ; preds = %19
  %23 = load i32, i32* %7, align 4
  %24 = load i32, i32* %6, align 4
  %25 = load i32, i32* %6, align 4
  %26 = mul nsw i32 %25, 800
  %27 = load i32, i32* %7, align 4
  %28 = add nsw i32 %26, %27
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [480000 x i32], [480000 x i32]* %1, i64 0, i64 %29
  %31 = load i32, i32* %30, align 4
  call void @put_pixel(i32 %23, i32 %24, i32 %31)
  br label %32

32:                                               ; preds = %22
  %33 = load i32, i32* %7, align 4
  %34 = add nsw i32 %33, 1
  store i32 %34, i32* %7, align 4
  br label %19

35:                                               ; preds = %19
  br label %36

36:                                               ; preds = %35
  %37 = load i32, i32* %6, align 4
  %38 = add nsw i32 %37, 1
  store i32 %38, i32* %6, align 4
  br label %15

39:                                               ; preds = %15
  call void (...) @flush()
  br label %11

40:                                               ; preds = %11
  ret void
}

declare dso_local void @put_pixel(i32, i32, i32) #1

declare dso_local void @flush(...) #1

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
