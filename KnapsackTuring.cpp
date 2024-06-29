#include "KnapasackTuring.h"

KnapsackTuringMachine::KnapsackTuringMachine(const std::vector<int>& tapes, int capacity, int numItems):
    intputtape(tapes), capacity(capacity), numItems(numItems), i(numItems), j(capacity), knapsackState(READ_CAPACITY),
    current_value(0), current_weight(0),steps(0), tapeSpace(0),worksteps(0),L1(0),L2(0),MAX(0),Finalmax(0),flag(0){
    worktape.resize((capacity + 1)*numItems, 0);// 初始化工作磁带
    tapeSpace+=(capacity+1)*numItems;
    outputtape.resize(numItems, 0);
}

// 读取背包容量
void KnapsackTuringMachine::readCapacity() {

    capacity = intputtape[0];
    knapsackState = READ_NUM; // 转移到读取物品数量状态
}

// 读取物品数量
void KnapsackTuringMachine::readNum() {

    numItems = intputtape[1];
    knapsackState = READ_WEIGHT; // 转移到读取物品重量状态
}

// 读取当前物品的重量
void KnapsackTuringMachine::readWeight() {

        current_weight = intputtape[i*2];
        knapsackState = READ_VALUE; // 转移到读取物品价值状态
}

// 读取当前物品的价值
void KnapsackTuringMachine::readValue() {

    current_value = intputtape[i*2+1];
    if(i==numItems)
    knapsackState = WRITE_M; // 转移到写入M状态
    else
        knapsackState = READ_M;//转移到读取M状态
}

void KnapsackTuringMachine::readM() {
     if(j<current_weight) {
         knapsackState = WRITE_M;
     }
     else {
        worksteps=j+(i)*(capacity+1);
        L1=worktape[worksteps];
        knapsackState = CAL_M;
     }
}

void KnapsackTuringMachine::calm() {
    worksteps=j+(i)*(capacity+1) - current_weight;
    L2=worktape[worksteps]+current_value;
    knapsackState = CMP;
}

void KnapsackTuringMachine::cmp() {
    if(L1>L2)
        MAX=L1;
    else
        MAX=L2;
    knapsackState = WRITE_M;
}

// 写入M值
void KnapsackTuringMachine::writeM() {
    if (i > 0 && j >= current_weight&&i==numItems) {
        worktape[j+(i-1)*(capacity+1)] = current_value;
    }
    else if (i > 0&&i==numItems) {
        worktape[j+(i-1)*(capacity+1)] = 0;
    }
    else if(i > 0 && j >= current_weight&&i<numItems) {
        worktape[j+(i-1)*(capacity+1)] = MAX;
    }
    else if(i>0&&i<numItems) {
        worktape[j+(i-1)*(capacity+1)] = worktape[j+(i)*(capacity+1)];
    }
    if (j > 0) {
        j--;
        knapsackState = READ_VALUE;
    }
    else {
        cout << endl;
        i--;
        j = capacity;
        knapsackState = READ_WEIGHT;
    }
    if (i == 0){
        knapsackState = GET_M;
    }
}

void KnapsackTuringMachine::getM() {
    Finalmax=worktape[0];
    for (int w = 0; w <= capacity; w++) {
        if (worktape[w] > Finalmax) {
            Finalmax = worktape[w];
            flag=w;
        }
    }
    knapsackState = RESULT;
}

void KnapsackTuringMachine::readW() {
    current_weight = intputtape[(i+1)*2];
    flag=(i+1)*(capacity+1)+flag - current_weight;
    i++;
    knapsackState = RESULT;
}

void KnapsackTuringMachine::getresult() {
    if(i==numItems-1) {
        if(worktape[flag]!=0) {
            outputtape[i]=1;
        }
        else
            outputtape[i]=0;
        for(int h=0;h<numItems;h++) {
            cout<<outputtape[h]<<" ";
        }
        cout<<endl;
        knapsackState = KNAPSACK_SUCCESS;
    }
    else if(worktape[flag]==worktape[(i+1)*(capacity+1)+flag]) {
        outputtape[i]=0;
        flag=(i+1)*(capacity+1)+flag;
        i++;
        knapsackState=RESULT;
    }
        //如果这个物体有用到
    else {
        outputtape[i]=1;
        knapsackState = READ_W;
    }
}

// 执行状态机
int KnapsackTuringMachine::Kexecute() {
    knapsackState = READ_CAPACITY; // 初始化状态
    while (true) {
        steps++;
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
        case READ_M:
            readM();
            break;
        case CAL_M:
            calm();
            break;
        case CMP:
            cmp();
            break;
        case GET_M:
            getM();
            break;
        case READ_W:
            readW();
            break;
        case RESULT:
             getresult();
            break;
        case KNAPSACK_SUCCESS:
            for(int h=0;h<(capacity + 1)*numItems;h++) {
                cout<<worktape[h]<<" ";
            }
            cout<<endl;
            return Finalmax;
        }
    }
}

