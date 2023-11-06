// Online C compiler to run C program online
#include <stdio.h>
#define MAX_LENGTH 10

int cuts[MAX_LENGTH];


int maxprofit(int *prices, int len) {
    if (len == 0) return 0;
    int profit, i;
    profit = -10;
    int cut = -1;
    int max_val = 0;
    for (i = 1; i <= len; i++) {
        int current_profit = prices[i] + maxprofit(prices, len - i);
        if (current_profit > profit) {
            profit = current_profit;
            cut = i;
        }
    }
    cuts[len] = cut;
    return profit;
}

void printCutSize(int size) {
    printf("Cut sizes: ");
    while (size > 0) {
        printf("%d ", cuts[size]);
        size -= cuts[size];
    }
    printf("\n");
}

int main() {
    int length, size;

    printf("Enter the length of the rod: ");
    scanf("%d", &length);
    int prices[length + 1];
    prices[0] = 0;

    printf("Enter the price of each size cut:\n");
    for (int i = 1; i <= length; i++) {
        printf("Price for cut %d: ", i);
        scanf("%d", &prices[i]);
    }
    printf("\n\nEnter the desired size: ");
    scanf("%d", &size);
    int profit;
    profit = maxprofit(prices, size);
    printf("Maximum profit for cut size %d: %d\n", size, profit);

    printCutSize(size);

    return 0;
}

