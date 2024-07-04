//
// Created by Azure on 24-6-29.
//

#include "BackTrack.h"

struct Item {
    int weight;
    int value;
    float ratio;

    Item(int w, int v) : weight(w), value(v), ratio(v * 1.0 / w) {}
};
bool compareItems(const Item& a, const Item& b) {
    return a.ratio > b.ratio;  // 按照重量价值比递减排序
}

BackTrack::BackTrack() {
    N = 0;//
    capcity = 0;
    inputtap = {};
    worktap = {};
    output = {};
}


void BackTrack::initwork(vector<int> weight, vector<int> value,int cap) {
    current_in = 0;
    current_work = 0;
    current_out = 0;
    step = 0;
    this->bestv = 0;
    this->N = weight.size();
    this->capcity = cap;
    this->weight = weight;
    this->value = value;
    worktap.assign(3+N,0);
    output.assign(N,0);
    bestx.assign(N,0);

    vector<Item> items;
    // 创建Item对象并计算重量价值比
    for (int i = 0; i < N; ++i) {
        items.push_back(Item(weight[i], value[i]));
    }
    // 按照重量价值比递减排序
    sort(items.begin(), items.end(), compareItems);
    inputtap.push_back(N);
    inputtap.push_back(capcity);
    for (const auto& item : items) {
        inputtap.push_back(item.weight);
        inputtap.push_back(item.value);
    }
    work_stack.push({0,2});
}

void BackTrack::TuringStart() {
    scan();
    cout<<bestv<<endl;
    cout<<"step: "<<step<<endl;
    showoutput();
}

void BackTrack::scan() {
    int state;
    while(!work_stack.empty()) {
        float bound = 0;
        node current = work_stack.top();
        bool flag = true;
        state = 0;
        while(flag) {
            step++;
            switch(state) {
                case 0://叶节点判断+处理，
                    state = judgeleaf(current);
                break;
                case 9:
                    updatebestv(current);
                    popnode(current);
                    flag = false;
                break;
                case 1://判断节点访问次数，回
                    state = judgevis(current);
                    if(state==-1) {
                        flag = false;
                        popnode(current);
                    }
                break;
                case 2://判断下个物品能装入，能则生成左节点，否则判断右节点
                    if(compcap(current))
                        state = 5;
                    else
                        state = 3;
                break;
                case 3://计算上界
                    work_stack.top().xi = 0;
                    updatexi(current.n,0);
                    bound = calbound(current);
                case 4://比较上界和bestv
                    if(campbound(bound))
                        state = 6;
                    else
                        flag = false;
                break;
                case 5://压栈左孩子
                    updatexi(current.n,1);
                    work_stack.top().xi = 1;
                    pushleft(current);
                    flag = false;
                break;
                case 6://压栈右孩子
                    updatexi(current.n,0);
                    pushright(current);// 压栈右孩子
                    flag = false;
                break;
            }
        }
        showstack();
        showwork();
        cout<<endl;
    }
    updateoutput();
}
void BackTrack::readcval() {
    // 将 worktap[1] 的值赋给当前节点的 cval
    step++;
    current_work = 1;
    cval = worktap[1];
}

void BackTrack::writecval(int value) {
    // 将当前节点的 cval 写入 worktap[1]
    step++;
    current_work = 1;
    worktap[1] = value;
}

void BackTrack::readcwig() {
    // 将 worktap[0] 的值赋给当前节点的 cwig
    step++;
    current_work = 0;
    cwig = worktap[0];
}

void BackTrack::writecwig(int weight) {
    // 将当前节点的 cwig 写入 worktap[0]
    step++;
    current_work = 0;
    worktap[0] = weight;
}

bool BackTrack::campbound(float bound) {
    if(bound>bestv)
        return true;
    return false;
}

int BackTrack::judgeleaf(node current) {
    if(current.n>=N) {
        return 9;
    }
    return 1;
}
void BackTrack::readbestv() {
    step++;
    current_work = 2;
    if(cval>bestv) {
        bestv = worktap[current_work] = cval;
        updatebestx();
    }
}

void BackTrack::readwigi(int i) {
    step++;
    current_in = i*2+2;
}
void BackTrack::readvali(int i) {
    step++;
    current_in = i*2+3;
}

void BackTrack::updatexi(int n,int xi) {
    step++;
    current_work = 3+n;
    if(xi==2)
        worktap[current_work] = 0;
    else
        worktap[current_work] = xi;
}


void BackTrack::updatebestv(node current) {
    readcval();
    readbestv();
    cout<<"-------------------"<<bestv<<endl;
    //updatebestx();
    // for(int i=0;i<bestx.size();i++) {
    //     cout<<bestx[i]<<" ";
    // }
    // cout<<endl;
}
void BackTrack::updatebestx() {
    //step+=N;
    for(int i=0;i<N;i++) {
        current_work = 3+i;
        bestx[i]=worktap[current_work];
    }
}
void BackTrack::updateoutput() {
    for(int i=0;i<N;i++) {
        output[i] = bestx[i];
    }
}

int BackTrack::judgevis(node current) {
    //current_work = current.n+3;
    if(current.xi==0) {
        return -1;
    }else if(current.xi==1)
        return 3;
    else
        return 2;
}
bool BackTrack::compcap(node current) {
    readcwig();
    readwigi(current.n);
    if(inputtap[current_in]+worktap[current_work]<=capcity) {//处理左孩子
        return true;
    }
    return false;
}

void BackTrack::pushleft(node current) {

    readcwig();
    readwigi(current.n);
    int newWeight = worktap[current_work] + inputtap[current_in];
    readcval();
    current_in++;
    int newValue = worktap[current_work] + inputtap[current_in];
    //step+=2;
    writecwig(newWeight);
    writecval(newValue);
    work_stack.push({current.n+1,2});
}

int BackTrack::calbound(node current) {
    readcval();
    float bound = worktap[current_work];
    readcwig();
    int totalWeight = worktap[current_work];
    for (int i = current.n+1; i < N; ++i) {
        readwigi(i);
        if (totalWeight + inputtap[current_in] <= capcity) {
            totalWeight += inputtap[current_in];
            readvali(i);
            bound += inputtap[current_in];
        } else {
            float t = (capcity - totalWeight) * 1.0/inputtap[current_in];
            readvali(i);
            t*=inputtap[current_in];
            bound += t;
            break;
        }
    }
    return bound;
}


void BackTrack::pushright(node current) {

    // readcv();
    // int newValue = worktap[current_work] + value[current.n];
    // readcw();
    // int newWeight = worktap[current_work] + weight[current.n];
    work_stack.push({current.n+1,2});
}

void BackTrack::popnode(node current) {
    work_stack.pop();
    updatexi(current.n,2);
    if(!work_stack.empty()&&work_stack.top().xi==1) {
        worktap[0] -=weight[current.n-1];
        worktap[1] -= value[current.n-1];
        cout<<current.n<<"------------------------"<<worktap[0]<<" "<<worktap[1]<<endl;
        // int a;
        // cin>>a;

    }
}


void BackTrack::showinput() {
    for(int i=0;i<inputtap.size();i++) {
        cout<<inputtap[i]<<" ";
    }
}

void BackTrack::showwork() {
    for(int i=0;i<worktap.size();i++) {
        cout<<worktap[i]<<" ";
    }
    cout<<endl;
}

void BackTrack::showoutput() {
    for(int i=0;i<output.size();i++) {
        cout<<output[i]<<" ";
    }
    cout<<endl;
}


void BackTrack::showstack() {
    stack<node> temp = work_stack;
    node t ;
    static int time = 0;
    time++;
    cout<<"time: "<<time<<endl;
    while(!temp.empty()) {
        t = temp.top();
        temp.pop();
        if(t.xi!=2)
        cout<<" n "<<t.n<<" xi "<<t.xi<<endl;
        else
            cout<<" n "<<t.n<<endl;
    }
    cout<<"------"<<endl;
}


// void BackTrack::scan() {
//     //先模拟栈的运行，再调整
//     while(!work_stack.empty()) {
//         showstack();
//         node current = work_stack.top();
//         if(current.n>=N) {
//             bestv = current.cval;
//             cout<<"-------------------"<<bestv<<endl;
//             work_stack.pop();
//             continue;;
//         }
//
//         if(current.vis==0) {
//             if(weight[current.n]+current.cwig<=capcity) {//处理左孩子
//                 work_stack.top().vis = 1;
//                 pushleft(current);
//             }else {//处理右孩子
//                 // 修改栈顶visit，不算步数
//                 work_stack.top().vis = 2;
//                 //计算bound
//                 int a = calbound(current);
//                 cout<<"bound: "<<current.n<<" "<<a<<endl;
//                 if(a>bestv) {
//                     pushright(current);// 压栈右孩子
//                 }
//                 else {
//                     //剪枝
//                 }
//
//             }
//         }else if(current.vis==1) {//处理右孩子
//             // 修改栈顶visit，不算步数
//             work_stack.top().vis = 2;
//             //计算bound
//             int a = calbound(current);
//             cout<<"bound: "<<current.n<<" "<<a<<endl;
//             if(a>bestv) {
//                 pushright(current);// 压栈右孩子
//             }
//             else {
//                 //不
//             }
//         }else {//访问过两次
//             work_stack.pop();
//         }
//     }
// }