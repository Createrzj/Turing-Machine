//
// Created by 11356 on 2024/6/27.
//

#ifndef KNAPASACKTURING_H
#define KNAPASACKTURING_H
#include <vector>
#include <iostream>
using namespace std;
class KnapsackTuringMachine {
public:
    KnapsackTuringMachine(const std::vector<int>& tapes, int capacity, int numItems);
    int Kexecute();
    int getSteps() const { return steps; }
    int getTapeSpace() const { return tapeSpace; }

private:
    enum KnapsackState {
        READ_CAPACITY, READ_NUM, READ_WEIGHT, READ_VALUE,
        WRITE_M, KNAPSACK_SUCCESS,RESULT,READ_M,CAL_M,CMP,
        READ_W,GET_M
    };
    int steps;
    int tapeSpace;
    std::vector<int> intputtape;
    std::vector<int> worktape;
    std::vector<int> outputtape;
    int capacity; // ��������
    int numItems; // ��Ʒ����
    int i, j; // ��ǰ��Ʒ�������͵�ǰ����������
    int current_value, current_weight; // ��ǰ��Ʒ�ļ�ֵ������
    int worksteps;
    KnapsackState knapsackState; // ��ǰ״̬
    int L1,L2,MAX;//���ڼ�¼
    int Finalmax;
    int flag;
    void readValue();
    void readWeight();
    void readNum();
    void readCapacity();
    void readM();
    void writeM();
    void getresult();
    void calm();
    void cmp();
    void readW();
    void getM();
};



#endif //KNAPASACKTURING_H
