#include "KnapasackTuring.h"

KnapsackTuringMachine::KnapsackTuringMachine(const std::vector<int>& tapes, int capacity, int numItems):
    intputtape(tapes), capacity(capacity), numItems(numItems), i(numItems), j(capacity), knapsackState(READ_CAPACITY),
    current_value(0), current_weight(0),steps(0), tapeSpace(0){
    worktape.resize((capacity + 1)*numItems, 0);// 初始化工作磁带
    tapeSpace+=(capacity+1)*numItems;
}

// 读取背包容量
void KnapsackTuringMachine::readCapacity() {
    steps++;
    capacity = intputtape[0];
    knapsackState = READ_NUM; // 转移到读取物品数量状态
}

// 读取物品数量
void KnapsackTuringMachine::readNum() {
    steps++;
    numItems = intputtape[1];
    knapsackState = READ_WEIGHT; // 转移到读取物品重量状态
}

// 读取当前物品的重量
void KnapsackTuringMachine::readWeight() {
        steps++;
        current_weight = intputtape[i*2];
        knapsackState = READ_VALUE; // 转移到读取物品价值状态
}

// 读取当前物品的价值
void KnapsackTuringMachine::readValue() {
    steps++;
    current_value = intputtape[i*2+1];
    knapsackState = WRITE_M; // 转移到写入M状态
}

// 写入M值
void KnapsackTuringMachine::writeM() {
    if (i > 0 && j >= current_weight&&i==numItems) {
        worktape[j+(i-1)*(capacity+1)] = max(worktape[j+(i-1)*(capacity+1)], worktape[j+(i-1)*(capacity+1) - current_weight] + current_value);
    }
    else if(i > 0 && j >= current_weight&&i<numItems) {
        worktape[j+(i-1)*(capacity+1)] = max(worktape[j+(i)*(capacity+1)], worktape[j+(i)*(capacity+1) - current_weight] + current_value);
    }
    else if (i > 0&&i==numItems) {
        worktape[j] = worktape[j];
    }
    else if(i>0&&i<numItems) {
        worktape[j] = worktape[j+(i)*(capacity+1)];
    }
    if (j > 0) {
        j--;
        knapsackState = WRITE_M;
    }
    else {
        cout << endl;
        i--;
        j = capacity;
        knapsackState = READ_WEIGHT;
    }
    if (i == 0){
        knapsackState = RESULT;
    }
}

void KnapsackTuringMachine::getresult() {
    int flag=0;
    int result[numItems]={0};
    tapeSpace+=numItems;
    for(int i=0;i<numItems;i++) {
     int max=worktape[0];
        for (int w = 0; w <= capacity; w++) {
            if (worktape[w] > max) {
                steps++;
                max = worktape[w];
                flag=w;
            }
        }
        if(worktape[flag]==worktape[(i+1)*(capacity+1)+flag]) {
            result[i]=0;
            flag=(i+1)*(capacity+1)+flag;
        }
        //如果这个物体有用到
        else {
            result[i]=1;
            flag=(i+1)*(capacity+1)+flag - intputtape[(i+1)*2];
        }
    }
    for(int w=0;w<numItems;w++) {
        cout<<result[w]<<" ";
    }
        cout<<endl;
}

// 执行状态机
int KnapsackTuringMachine::Kexecute() {
    knapsackState = READ_CAPACITY; // 初始化状态
    int max;
    while (true) {
        switch (knapsackState) {
        case READ_CAPACITY:
            readCapacity();
            break;
        case READ_NUM:
            readNum();
            break;
        case READ_WEIGHT:
            readWeight();
            break;
        case READ_VALUE:
            readValue();
            break;
        case WRITE_M:
            writeM();
            break;
        case RESULT:
            getresult();
            break;
        case KNAPSACK_SUCCESS:
            max=worktape[0];
            for (int i = 0; i <= capacity; i++) {
                if (worktape[i] > max)
                    max = worktape[i];
            }
            for(int h=0;h<(capacity + 1)*numItems;h++) {
                cout<<worktape[h]<<" ";
            }
            cout<<endl;
            return max;
        }
    }
}

