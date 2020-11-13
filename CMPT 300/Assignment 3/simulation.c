#include <stdio.h>
#include "list.h"
#include <stdbool.h>

struct PCB {
    int PID;
    int priority; // 0 = high, 1 = norm, 2 = low
    int state; // 1 = running, 2 = ready, 3 = blocked
    char message[50];
    LIST *queue;
};

// Currently running process
struct PCB runningProcess;

void init(LIST *queueParam) {
    struct PCB initProcess;

    initProcess.PID = 0;
    initProcess.priority = 2;
    initProcess.state = 1;
    initProcess.queue = queueParam;

    runningProcess = initProcess;
}

void createProcess(int PIDParam, int priorityParam, LIST *queueParam) {
    struct PCB newProcess;

    newProcess.PID = PIDParam;
    newProcess.priority = priorityParam;

    //if (runningProcess->PID == 0){
    //    newProcess->state = 1;
    //} else {
    //    newProcess->state = 2;
    //}

    newProcess.queue = queueParam;

    if (ListAppend(queueParam, &newProcess) == 0) {
        printf("Success: Process created, process id: ");
        printf("%d \n\n", newProcess.PID);

    } else {
        printf("Failure: Cannot create process\n\n");
    }
}

void forkProcess() {
    struct PCB currentRunningProcess = runningProcess;

    ListAppend(runningProcess.queue, &currentRunningProcess);

    currentRunningProcess.state = 2;

    // Set running process id to 0 for next process in queue to run
    runningProcess.PID = 0;
}

void killProcess(int PID) {
    //ListRemove(list)
}

void exitProcess() {
    struct LIST *currentProcessQueue = runningProcess.queue;

    if (ListRemove(currentProcessQueue) == 0) {
        printf("Success: Process removed, new processing ID: ");
        //printf("%d \n\n", currentProcessQueue->PID);

    } else {
        printf("Failure: Process not removed\n\n");
    }
}

void sendMessage(int PIDParam, char *msg) {

}

void semaphoreP(int semID) {

}

void semaphoreV(int semID) {

}

void totalInfo(LIST *queue0Param, LIST *queue1Param, LIST *queue2Param) {

    if (ListCount(queue0Param) > 0) {
        printf("In priority 0 ready queue: \n\n");
        struct PCB *firstProcess0 = ListFirst(queue0Param);
        printf("Process 1 PID: ");
        printf("%d \n", firstProcess0->PID);

        printf("Process 1 Priority: ");
        printf("%d \n", firstProcess0->priority);

        printf("Process 1 State: ");
        printf("%d \n", firstProcess0->state);
    }

    if (ListCount(queue1Param) > 0) {
        printf("In priority 1 ready queue: \n\n");
        struct PCB *firstProcess1 = ListFirst(queue1Param);
        printf("Process 1 PID: ");
        printf("%d \n", firstProcess1->PID);

        printf("Process 1 Priority: ");
        printf("%d \n", firstProcess1->priority);

        printf("Process 1 State: ");
        printf("%d \n", firstProcess1->state);
    }

    if (ListCount(queue2Param) > 0) {
        printf("In priority 2 ready queue: \n\n");
        struct PCB *firstProcess2 = ListFirst(queue2Param);
        printf("Process 1 PID: ");
        printf("%d \n", firstProcess2->PID);

        printf("Process 1 Priority: ");
        printf("%d \n", firstProcess2->priority);

        printf("Process 1 State: ");
        printf("%d \n", firstProcess2->state);
    }

    /*for (int i = 0; i < queue0Param->mynodes; i++){
        printf("%d Process \n\n", i);
        printf("PID: %d \n", queue1Param->curitem);
        printf("Priority: %d \n", queue1Param->curitem);
        //printf("State: %d \n", queue1Param->curitem->state);
    }*/
}

int main() {

    struct LIST *priority0PCB, *priority1PCB, *priority2PCB, *waitingSendQueue, *waitingReceiveQueue;

    // 3 ready queues, one for each type of priority
    priority0PCB = ListCreate();
    priority1PCB = ListCreate();
    priority2PCB = ListCreate();

    // a queue of processes waiting on a send operation (i.e. waiting for a reply)
    waitingSendQueue = ListCreate();

    // a queue of processes waiting on a receive operation
    waitingReceiveQueue = ListCreate();

    init(priority2PCB);

    int PID = 0000;

    bool runMenu = true;

    while (runMenu) {
        // Menu
        char command;
        printf("Enter a command (to exit type !): ");
        command = getchar();

        if (command == 'c' || command == 'C') {
            int priority;
            printf("Enter a priority (0 = high, 1 = norm, 2 = low): ");
            scanf("%d", &priority);

            if (priority == 0) {
                createProcess(PID + 1, priority, priority0PCB);
                PID = PID + 1;
            } else if (priority == 1) {
                createProcess(PID + 1, priority, priority1PCB);
                PID = PID + 1;
            } else if (priority == 2) {
                createProcess(PID + 1, priority, priority2PCB);
                PID = PID + 1;
            }


        } else if (command == 'f' || command == 'F') {
            forkProcess();
/*    } else if (command == 'k' || command == 'K'){
        int killPID = 0;
        printf("Enter a PID: ");
        scanf("%d", &killPID);
        killProcess(killPID);
*/
        } else if (command == 'e' || command == 'E') {
            exitProcess();
        } else if (command == 't' || command == 'T') {
            totalInfo(priority0PCB, priority1PCB, priority2PCB);
        }

/*else if (command == 's' || command == 'S'){
        int sendPID = 0;
        printf("Enter a PID: ");
        scanf("%d", &sendPID);

        char *msg;
        printf("Enter a message: ");
        scanf("%c", &msg);

        sendMessage(sendPID, msg);
    } else if (command == 'p' || command == 'P'){
        int semID = 0;
        printf("Enter a semaphore ID: ");
        scanf("%d", &semID);

        semaphoreP(semID);
    } else if (command == 'v' || command == 'V'){
        int semID = 0;
        printf("Enter a semaphore ID: ");
        scanf("%d", &semID);

        semaphoreV(semID);
    } */
        else if (command == '!') {
            runMenu = false;
        }

    }

    return 0;
}



