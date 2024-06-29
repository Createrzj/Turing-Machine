//
// Created by Azure on 2024/6/27.
//

#include "Recur_kanp.h"


Recur_kanp::Recur_kanp() {
    step = 0;
    grid = 0;
    capcity = 0;
    current_in = 0;
    current_work = 0;
    current_put = 0;
}

void Recur_kanp::initwork(vector<int>& weights, vector<int>& values, int capcity) {
    if(weights.size()!=values.size()) {
        cout<<"ERROR input";
        return;
    }
    this->capcity = capcity;
    this->value = values;
    this->weight = weights;
    int n = weight.size();
    for(int i=0;i<n;i++) {
        inputtap.push_back(weight[i]);
        inputtap.push_back(value[i]);
    }
    this->capcity = capcity;

    N = n;
    output.assign(n,0);
    this->memo.assign(n+1, vector<int>(capcity + 1, -1));
    for(int i=0;i<=capcity;i++)
        memo[0][i] = 0;
    for(int i=0;i<=n;i++)
        memo[i][0] = 0;
    while (!work_stack.empty()) work_stack.pop();
    work_stack.push({capcity, n,1});
}

void Recur_kanp::TuringStart() {
    scan();
    getmaxvule();
    printmemo();

    traceSolution() ;
    cout<<step<<endl;
}

void Recur_kanp::scan() {
    while (!work_stack.empty()) {
        step++;
        //this->printstack();

        Frame frame = work_stack.top();//递归直接传值速度快。？不用读写
        work_stack.pop();
        // int cap = frame.cap;
        // int n = frame.n;
        // int state = frame.state;

        int flag = 1;
        while(flag!=0) {
            switch(frame.state) {
                case 1:
                    readmemo(frame);
                    push_write(frame);
                    flag = frame.state == 3?1:0;
                break;
                // case 2:
                //     writememo1(frame);
                //     flag = 0;
                // break;
                case 3:
                    comparewig(frame);
                break;
                case 4:
                    pushstack_1(frame);
                    flag=0;
                break;
                case 5:
                    pushstack_2(frame);
                    flag = 0;
                break;
                case 6:
                    flag = 0;
                    writemax(frame);
                // printmemo();
                // cout<<endl;
                // int a;
                // cin>>a;
                break;
            }
        }

    }
}
// void Recur_kanp::getstack() {
//
// }

void Recur_kanp::push_write(Frame &frame) {//state 1
    if(frame.cap<=0||frame.n<=0) {
        //frame.state = 2;
        writememo1(frame);
    }else if(memo[frame.n][frame.cap]==-1){
        frame.state = 3;
    }else {
        frame.state = -1;
    }
}

void Recur_kanp::writememo1(Frame &frame) {//state 2
    memo[frame.n][frame.cap] = 0;
}

void Recur_kanp::readmemo(Frame &frame) {
    step++;
    current_work = frame.n*(capcity+1)+frame.cap;//index
}

void Recur_kanp::readmemo(int n, int cap) {
    step++;
    current_work = n*(capcity+1)+cap;
}


void Recur_kanp::readwig(Frame &frame) {
    step++;
    current_in = (frame.n-1)*2;
}

void Recur_kanp::readwig(int n) {
    step++;
    current_in = (n-1)*2;
}

void Recur_kanp::readval(Frame &frame) {
    step++;
    current_in = (frame.n-1)*2+1;
}

void Recur_kanp::comparewig(Frame& frame) {//state 3
    readwig(frame);
    //weight[frame.n-1]
    if (inputtap[current_in] > frame.cap) {
        frame.state = 4;
    }else {
        frame.state = 5;
    }
}

void Recur_kanp::pushstack_1(Frame &frame) {//state 4
    work_stack.push({frame.cap, frame.n-1, 1});//不取
}

void Recur_kanp::pushstack_2(Frame &frame) {//state 5
    work_stack.push({frame.cap, frame.n, 6});//合并问题
    work_stack.push({frame.cap, frame.n-1, 1});//不取
    work_stack.push({frame.cap - inputtap[current_in], frame.n-1, 1});//取
                                        //weight[frame.n-1]
}

void Recur_kanp::writemax(Frame& frame) {//state 6
    Frame t = {frame.cap,frame.n,-1};
    readmemo(t);
    int value_no = memo[frame.n-1][frame.cap];//不取

    t = {frame.cap,frame.n,-1};
    readval(t);
    int value_yes = inputtap[current_in] ;//value[n-1];
    readwig(t);                              //weight[n-1]
    value_yes+=memo[frame.n-1][frame.cap -inputtap[current_in]];//取
    readmemo(frame);

    //int value_no = memo[frame.n-1][frame.cap];//不取
    //int value_yes = value[frame.n-1]+ memo[frame.n-1][frame.cap -weight[frame.n-1]];
    memo[frame.n][frame.cap] = max(value_yes, value_no);
}

void Recur_kanp::getmaxvule() {
    cout<<memo[weight.size()][capcity]<<endl;
}

int Recur_kanp::getstacksize() {
    return work_stack.size();
}

void Recur_kanp::printstack() {
    stack<Frame> temp = work_stack;
    Frame t ;
    static int time = 0;
    //static int ye = 0;
    time++;
    cout<<"time: "<<time<<endl;
    while(!temp.empty()) {
        t = temp.top();
        temp.pop();
        cout<<"cap "<<t.cap<<" n "<<t.n<<" state "<<t.state<<endl;
        // if(t.n==0||t.cap==0) {
        //     ye++;
        // }
    }
    cout<<"------"<<endl;
    //cout<<"ye:"<<ye<<endl;
}

void Recur_kanp::printmemo() {
    // for(int i=0;i<inputtap.size();i++) {
    //     cout<<inputtap[i]<<'\t';
    // }
    // cout<<endl;
    for(int i=0;i<memo.size();i++) {
        for(int j=0;j<memo[i].size();j++) {
            cout<<memo[i][j]<<'\t';
        }
        cout<<endl;
    }
}

void Recur_kanp::traceSolution() {
    int cap = capcity;
    for (int i = N; i > 0; i--) {
        current_put = i-1;
        readmemo(i,cap);
        int now = memo[i][cap];
        readmemo(i,cap);
        int pre = memo[i-1][cap];
        if (now != pre) {
            step++;
            output[current_put] = 1;
            //      weight[i-1]
            readwig(i);
            cap -= inputtap[current_in];
        }
    }
    cout << "Solution: ";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << ' ';
    }
    cout << endl;
}



