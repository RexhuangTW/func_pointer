# func_pointer

為什麼要用Function Pointer？
設計初期就採用Function Pointer的方式的話，當code越來越多、越來越複雜時比較方便維護。
A team 開發使需使用B team 開發的library 可配合 dlopen 及 dlsym 加速平行開發及簡化維護。
使用Callback function前，必須了解如何使用Function Pointer。
