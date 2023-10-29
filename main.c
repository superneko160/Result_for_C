#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// Result型のエラーを表す列挙型
typedef enum {
    OK,         // 成功
    ERR_INVALID, // 無効な値
    ERR_OVERFLOW // オーバーフロー
} ResultCode;

// Result型構造体
typedef struct {
    ResultCode code; // 結果のコード
    int value;       // 結果の値 (成功時のみ)
} Result;

// Result型のファクトリ関数（成功時）
Result Ok(int value) {
    Result result;
    result.code = OK;
    result.value = value;
    return result;
}

// Result型のファクトリ関数（エラー時）
Result Err(ResultCode code) {
    Result result;
    result.code = code;
    return result;
}

// プリント関数
void printResult(Result result) {
    switch (result.code) {
        case OK:
            printf("Result: OK, Value: %d\n", result.value);
            break;
        case ERR_INVALID:
            printf("Result: ERR_INVALID\n");
            break;
        case ERR_OVERFLOW:
            printf("Result: ERR_OVERFLOW\n");
            break;
        default:
            printf("Result: Unknown\n");
            break;
    }
}

// メイン関数
int main() {
    Result result1 = Ok(32);     // 成功のResult
    Result result2 = Err(ERR_INVALID); // エラーのResult

    printResult(result1);
    printResult(result2);

    return 0;
}
