#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// パチンコの当たりをシミュレートする関数
int simulatePachinko(double probability) {
    int spins = 0;
    double randomValue;
    
    // ランダム値を生成して当たりまでの回転数をカウント
    do {
        randomValue = (double)rand() / RAND_MAX;
        spins++;
    } while (randomValue > probability);

    return spins;
}

int main() {
    double probability;
    int spins;

    // 確率の入力
    printf("パチンコの当たり確率を入力してください（例：1/319の場合は0.0031）: ");
    scanf("%lf", &probability);

    // 乱数の初期化
    srand(time(NULL));

    // パチンコのシミュレーション
    spins = simulatePachinko(probability);

    // 結果の表示
    printf("当たるまでに %d 回転しました。\n", spins);

    return 0;
}