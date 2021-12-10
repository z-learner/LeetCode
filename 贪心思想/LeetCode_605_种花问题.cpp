#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1 && flowerbed[0] == 0){
            return --n <= 0;
        }
        for (int i = 0; i < flowerbed.size(); i++){
            if (flowerbed[i] == 0){
                if (i == 0){//左边界
                    if (flowerbed[i + 1] == 0){
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else if (i == flowerbed.size()-1){//右边界
                    if (flowerbed[i - 1] == 0){
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else{
                    if ((flowerbed[i + 1] == 0) && (flowerbed[i - 1] == 0)){
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
        }
        return n <= 0;
    }
};