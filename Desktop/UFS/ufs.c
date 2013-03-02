/*Version 1.0, Feb 2010

Copyright (C) 2010 Free Software Foundation, Inc.  
51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA

Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.
Copyright 2010 Kshitiz Agarwal 
the program is distributed under the terms of the GNU General Public License
This file is part of UFS.

UFS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

UFS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with UFS. If not, see <http://www.gnu.org/licenses/>. For any bug, kindly mail that to k.agarwal4@gmail.com */

#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sched.h>
#include <time.h>
int ufs_cls(char);
int cls();
int ufs_csl(char);
int csl();
int ufs_lcs(char);
int lcs();
int ufs_lsc(char);
int lsc();
int ufs_slc(char);
int slc();
int ufs_scl(char);
int scl();
int not, maxmem, maxtme;
struct task_struct
    {
        char PID[15];
        char memsze[10];
        char name[50];
        char policy[15];
        int time;  // burst time in mins
        int netflag;
        struct task_struct *link;
    };
struct task_struct *task, *Q, *init_task;
int main()
{
    int l, i=0, poly1 = SCHED_FIFO, poly2 = SCHED_RR, j, k, tme, ii=0, len, len1, jj, flag=0;
char name[100], word[100], c1[6], c2[2], lgfle[100], C[15], c3;
long long int lli;
FILE *F1, *fp, *F2;
system("sudo netstat -punta > lognet.txt");
    maxmem = 0;
    maxtme = 0;
    not = 0;
    system("sudo who -q > logusers.txt");
    system("sudo ps aux > logps.txt");
    fp = fopen("logps.txt","r"); 
    while(!feof(fp))  // 1
    {  
    fscanf(fp, "%s", word);
    F1 = fopen("logusers.txt", "r");
    while(!feof(F1))  
    {  // 2
      fscanf(F1, "%s", name);
      if(strcmp(name, "#")==0) 
         strcpy(name, "root");
      if(strcmp(name, word)==0)
   { // 3
     task = (struct task_struct*)malloc(sizeof(struct task_struct));
     task->link = '\0';
     fscanf(fp, "%s", word);
     strcpy(task->PID, word);
     fscanf(fp, "%s", word);
     fscanf(fp, "%s", word);
     strcpy(task->memsze, word);
     i = atoi(task->memsze);
     if(i>=100) strcpy(task->memsze, "99");
     if(i>maxmem) maxmem = i;
     for(i=1;i<=6;i++)
         fscanf(fp, "%s", word);
     k = strlen(word);
     for(i=0;i<=k-1;i++)
     {
         if(word[i]==':') break;
         c1[i] = word[i];
     }
     i++;
     j = atoi(c1);
     if(j>59) j=59;
     task->time = j/2 + 5;
     if(task->time>maxtme) maxtme = task->time;
     fscanf(fp, "%s", word);
     strcpy(task->name, word);
     lli = atoi(task->PID);
     if((sched_getscheduler(lli)==poly1)) 
         strcpy(task->policy, "SCHED_FIFO");
     else if((sched_getscheduler(lli)==poly2)) 
         strcpy(task->policy, "SCHED_RR");
     else strcpy(task->policy, "SCHED_OTHER");
     strcpy(C, task->PID); // C stores pid as string           
   len=strlen(C);   // itoa converts int to char*
   F2 = fopen("lognet.txt","r");
   strcat(C, "/");
   while(!feof(F2))  
   { // 4
   fscanf(F2, "%s", lgfle);
   if(strncmp(C, lgfle, len+1)==0) 
   {
      task->netflag = 1;
      break;
   }
   else task->netflag = 0;
    } // 4
     if(flag==0) init_task = task;
     if(flag>0) Q->link = task;
     flag++;
     Q = task;
    not++;
    fclose(F2);
    break;
    } } }// 3, 2, 1
    fclose(F1);
    fclose(fp);
    ii=0;
    fp = fopen("input1.txt","r");
    fscanf(fp, "%c", &c3);
    if(c3=='1') cls();
    else if(c3=='2') csl();
    else if(c3=='3') lcs();
    else if(c3=='4') lsc();
    else if(c3=='5') slc();
    else if(c3=='6') scl(); 
    else if(c3=='0') 
    {
          task = init_task;
          while(1)
          {
              j = atoi(task->PID);
              setpriority(PRIO_PROCESS, j, 0);
              if(task->link!='\0')
              task = task->link;
              if(ii==1) break;
              if(task->link=='\0') ii=1;
          }
          printf("\n");
          return (1);
    }
    else printf("\n\n INVALID ENTRY!!!\n\n");
    return (1);
}
int cls()
{
    char i;
    FILE *F;
    F = fopen("input2.txt","r");
    fscanf(F, "%c", &i);
    task = init_task;
    ufs_cls(i);
    return (1);
}
int ufs_cls(char opt)
    {  //  opt option for deciding purpose // lgfle stored logfile          
int i, k, len, len1, j, l, temp1, prio, n, a, m, b, temp2, wg, h, non, pol1, pol2, v, g, not9=0;
long int w;
struct task_struct_cls
{   
    char PID1[15];
    char memsze1[10];
    char name1[50];
    char policy1[15];
    int time1;  // burst time in mins
    int netflag1;
    struct task_struct_cls *link1;
};
struct mem_cls
    {
            struct task_struct_cls *task1, *init_task1, *Q1;
            int not1, flag1;
    };
struct time_cls
    {
            struct mem_cls M[100];
    };
struct conn_cls
    {
            struct time_cls T[2][60];
    };
struct conn_cls CN;
       float q, f;
       FILE *f1;
           // lgfle has output of “sudo netstat –p”
        
       i = ((maxmem+1)*(maxtme+1)); 
       if(i<6000) non = 2*i;
       else non = 12000;   // wg is for net weight 
       pol1 = SCHED_FIFO;  // wg1 for mem weight, wg2 for normal task weight
       pol2 = SCHED_RR;
       for(i=0;i<=maxtme;i++)
       {
           for(j=0;j<=maxmem;j++)
           {
             CN.T[0][i].M[j].not1 = 0;
             CN.T[0][i].M[j].flag1 = 0;
             CN.T[1][i].M[j].flag1 = 0;
             CN.T[1][i].M[j].not1 = 0;
           }
       }
       len=0;
       l=0;
       if(non>=40) 
       {
          temp1 = non/40;
          f = non/40.00;
          if(f-temp1>0.5) temp1 = temp1+1;
       }
       else temp1 = 1;
       if(non>=10) 
       {
          temp2 = non/10;
          f = non/10.00;
          if(f-temp2>0.5) temp2 = temp2+1;
       }
       else temp2 = 1;
       wg =0;
       task = init_task; 
       while(1)
       {
           i = task->netflag;
           j = task->time;
           k = atoi(task->memsze);
           if(j>59) j=59;
           if(k>99) k=99;
           CN.T[i][j].M[k].task1 = (struct task_struct_cls*)malloc(sizeof(struct task_struct_cls));
           CN.T[i][j].M[k].task1->link1 = '\0';
           l = CN.T[i][j].M[k].not1;
           strcpy(CN.T[i][j].M[k].task1->PID1, task->PID);
           strcpy(CN.T[i][j].M[k].task1->memsze1, task->memsze);
           strcpy(CN.T[i][j].M[k].task1->name1, task->name);
       strcpy(CN.T[i][j].M[k].task1->policy1, task->policy);              
       CN.T[i][j].M[k].task1->time1 = task->time;
       CN.T[i][j].M[k].task1->netflag1 = i;      
       l++;
       CN.T[i][j].M[k].not1 = l;
       if(CN.T[i][j].M[k].flag1==0) CN.T[i][j].M[k].init_task1 = CN.T[i][j].M[k].task1;
       if(CN.T[i][j].M[k].flag1>0) CN.T[i][j].M[k].Q1->link1 = CN.T[i][j].M[k].task1;
       CN.T[i][j].M[k].flag1++;
       CN.T[i][j].M[k].Q1 = CN.T[i][j].M[k].task1;
       if(task->link!='\0')
       task = task->link;
       if(wg==1) break;
       if(task->link=='\0') wg=1;
       }    // closing task loop
    a=-20;
    b=-20;  
    v=0;  // for real time processes 
    n=0; // for normal processes
    if(opt=='1')    // internet is preferred, mem from low to high
    {  // 1
      f1 = fopen("output1_cls.txt","w");
     fprintf(f1, "\n1 - Internet + small + light tasks\n2 - Normal + small + light tasks\n3 - Internet + small + heavy tasks\n4 - Normal + small + heavy tasks\n5 - Internet + large + light tasks\n6 - Normal + large + light tasks\n7 - Internet + large + heavy tasks\n8 - Normal + large + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].init_task1;
          if(CN.T[1][j].M[h].not1>0) 
          { //3
           for(l=0;l<=CN.T[1][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[1][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[1][j].M[h].task1->PID1, CN.T[1][j].M[h].task1->netflag1, CN.T[1][j].M[h].task1->memsze1, CN.T[1][j].M[h].task1->time1, prio, CN.T[1][j].M[h].task1->policy1, CN.T[1][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[1][j].M[h].task1->link1!='\0')
  CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].init_task1;
          if(CN.T[0][j].M[h].not1>0) 
          { //3
             for(l=0;l<=CN.T[0][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[0][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[0][j].M[h].task1->PID1, CN.T[0][j].M[h].task1->netflag1, CN.T[0][j].M[h].task1->memsze1, CN.T[0][j].M[h].task1->time1, prio, CN.T[0][j].M[h].task1->policy1, CN.T[0][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[0][j].M[h].task1->link1!='\0')
  CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_cls'\n\n", opt);
    } // cl 1
    else if(opt=='2')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output2_cls.txt","w");
     fprintf(f1, "\n1 - Internet + small + light tasks\n2 - Normal + small + light tasks\n3 - Internet + small + heavy tasks\n4 - Normal + small + heavy tasks\n5 - Internet + large + light tasks\n6 - Normal + large + light tasks\n7 - Internet + large + heavy tasks\n8 - Normal + large + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].init_task1;
          if(CN.T[0][j].M[h].not1>0) 
          { //3
             for(l=0;l<=CN.T[0][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[0][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[0][j].M[h].task1->PID1, CN.T[0][j].M[h].task1->netflag1, CN.T[0][j].M[h].task1->memsze1, CN.T[0][j].M[h].task1->time1, prio, CN.T[0][j].M[h].task1->policy1, CN.T[0][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[0][j].M[h].task1->link1!='\0')
  CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].init_task1;
          if(CN.T[1][j].M[h].not1>0) 
          { //3
           for(l=0;l<=CN.T[1][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[1][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[1][j].M[h].task1->PID1, CN.T[1][j].M[h].task1->netflag1, CN.T[1][j].M[h].task1->memsze1, CN.T[1][j].M[h].task1->time1, prio, CN.T[1][j].M[h].task1->policy1, CN.T[1][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[1][j].M[h].task1->link1!='\0')
  CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_cls'\n\n", opt);
    } // cl 1
    else if(opt=='3')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output3_cls.txt","w");
     fprintf(f1, "\n1 - Internet + small + light tasks\n2 - Normal + small + light tasks\n3 - Internet + small + heavy tasks\n4 - Normal + small + heavy tasks\n5 - Internet + large + light tasks\n6 - Normal + large + light tasks\n7 - Internet + large + heavy tasks\n8 - Normal + large + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].init_task1;
          if(CN.T[1][j].M[h].not1>0) 
          { //3
           for(l=0;l<=CN.T[1][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[1][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[1][j].M[h].task1->PID1, CN.T[1][j].M[h].task1->netflag1, CN.T[1][j].M[h].task1->memsze1, CN.T[1][j].M[h].task1->time1, prio, CN.T[1][j].M[h].task1->policy1, CN.T[1][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[1][j].M[h].task1->link1!='\0')
  CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].init_task1;
          if(CN.T[0][j].M[h].not1>0) 
          { //3
             for(l=0;l<=CN.T[0][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[0][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[0][j].M[h].task1->PID1, CN.T[0][j].M[h].task1->netflag1, CN.T[0][j].M[h].task1->memsze1, CN.T[0][j].M[h].task1->time1, prio, CN.T[0][j].M[h].task1->policy1, CN.T[0][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[0][j].M[h].task1->link1!='\0')
  CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_cls'\n\n", opt);
    } // cl 1
    else if(opt=='4') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output4_cls.txt","w");
     fprintf(f1, "\n1 - Internet + small + light tasks\n2 - Normal + small + light tasks\n3 - Internet + small + heavy tasks\n4 - Normal + small + heavy tasks\n5 - Internet + large + light tasks\n6 - Normal + large + light tasks\n7 - Internet + large + heavy tasks\n8 - Normal + large + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].init_task1;
          if(CN.T[0][j].M[h].not1>0) 
          { //3
             for(l=0;l<=CN.T[0][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[0][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[0][j].M[h].task1->PID1, CN.T[0][j].M[h].task1->netflag1, CN.T[0][j].M[h].task1->memsze1, CN.T[0][j].M[h].task1->time1, prio, CN.T[0][j].M[h].task1->policy1, CN.T[0][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[0][j].M[h].task1->link1!='\0')
  CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
         { // 2
          CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].init_task1;
          if(CN.T[1][j].M[h].not1>0) 
          { //3
           for(l=0;l<=CN.T[1][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[1][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[1][j].M[h].task1->PID1, CN.T[1][j].M[h].task1->netflag1, CN.T[1][j].M[h].task1->memsze1, CN.T[1][j].M[h].task1->time1, prio, CN.T[1][j].M[h].task1->policy1, CN.T[1][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[1][j].M[h].task1->link1!='\0')
  CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_cls'\n\n", opt);
    } // cl 1
else if(opt=='5')    // internet is preferred, mem from low to high
    {  // 1
      f1 = fopen("output5_cls.txt","w");
     fprintf(f1, "\n1 - Internet + small + light tasks\n2 - Normal + small + light tasks\n3 - Internet + small + heavy tasks\n4 - Normal + small + heavy tasks\n5 - Internet + large + light tasks\n6 - Normal + large + light tasks\n7 - Internet + large + heavy tasks\n8 - Normal + large + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].init_task1;
          if(CN.T[1][j].M[h].not1>0) 
          { //3
           for(l=0;l<=CN.T[1][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[1][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[1][j].M[h].task1->PID1, CN.T[1][j].M[h].task1->netflag1, CN.T[1][j].M[h].task1->memsze1, CN.T[1][j].M[h].task1->time1, prio, CN.T[1][j].M[h].task1->policy1, CN.T[1][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[1][j].M[h].task1->link1!='\0')
  CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].init_task1;
          if(CN.T[0][j].M[h].not1>0) 
          { //3
             for(l=0;l<=CN.T[0][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[0][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[0][j].M[h].task1->PID1, CN.T[0][j].M[h].task1->netflag1, CN.T[0][j].M[h].task1->memsze1, CN.T[0][j].M[h].task1->time1, prio, CN.T[0][j].M[h].task1->policy1, CN.T[0][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[0][j].M[h].task1->link1!='\0')
  CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_cls'\n\n", opt);
    } // cl 1
    else if(opt=='6')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output6_cls.txt","w");
     fprintf(f1, "\n1 - Internet + small + light tasks\n2 - Normal + small + light tasks\n3 - Internet + small + heavy tasks\n4 - Normal + small + heavy tasks\n5 - Internet + large + light tasks\n6 - Normal + large + light tasks\n7 - Internet + large + heavy tasks\n8 - Normal + large + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].init_task1;
          if(CN.T[0][j].M[h].not1>0) 
          { //3
             for(l=0;l<=CN.T[0][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[0][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[0][j].M[h].task1->PID1, CN.T[0][j].M[h].task1->netflag1, CN.T[0][j].M[h].task1->memsze1, CN.T[0][j].M[h].task1->time1, prio, CN.T[0][j].M[h].task1->policy1, CN.T[0][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[0][j].M[h].task1->link1!='\0')
  CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].init_task1;
          if(CN.T[1][j].M[h].not1>0) 
          { //3
           for(l=0;l<=CN.T[1][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[1][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[1][j].M[h].task1->PID1, CN.T[1][j].M[h].task1->netflag1, CN.T[1][j].M[h].task1->memsze1, CN.T[1][j].M[h].task1->time1, prio, CN.T[1][j].M[h].task1->policy1, CN.T[1][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[1][j].M[h].task1->link1!='\0')
  CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_cls'\n\n", opt);
    } // cl 1
    else if(opt=='7')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output7_cls.txt","w");
     fprintf(f1, "\n1 - Internet + small + light tasks\n2 - Normal + small + light tasks\n3 - Internet + small + heavy tasks\n4 - Normal + small + heavy tasks\n5 - Internet + large + light tasks\n6 - Normal + large + light tasks\n7 - Internet + large + heavy tasks\n8 - Normal + large + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].init_task1;
          if(CN.T[1][j].M[h].not1>0) 
          { //3
           for(l=0;l<=CN.T[1][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[1][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[1][j].M[h].task1->PID1, CN.T[1][j].M[h].task1->netflag1, CN.T[1][j].M[h].task1->memsze1, CN.T[1][j].M[h].task1->time1, prio, CN.T[1][j].M[h].task1->policy1, CN.T[1][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[1][j].M[h].task1->link1!='\0')
  CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].init_task1;
          if(CN.T[0][j].M[h].not1>0) 
          { //3
             for(l=0;l<=CN.T[0][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[0][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[0][j].M[h].task1->PID1, CN.T[0][j].M[h].task1->netflag1, CN.T[0][j].M[h].task1->memsze1, CN.T[0][j].M[h].task1->time1, prio, CN.T[0][j].M[h].task1->policy1, CN.T[0][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[0][j].M[h].task1->link1!='\0')
  CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_cls'\n\n", opt);
    } // cl 1
    else if(opt=='8') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output8_cls.txt","w");
     fprintf(f1, "\n1 - Internet + small + light tasks\n2 - Normal + small + light tasks\n3 - Internet + small + heavy tasks\n4 - Normal + small + heavy tasks\n5 - Internet + large + light tasks\n6 - Normal + large + light tasks\n7 - Internet + large + heavy tasks\n8 - Normal + large + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].init_task1;
          if(CN.T[0][j].M[h].not1>0) 
          { //3
             for(l=0;l<=CN.T[0][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[0][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[0][j].M[h].task1->PID1, CN.T[0][j].M[h].task1->netflag1, CN.T[0][j].M[h].task1->memsze1, CN.T[0][j].M[h].task1->time1, prio, CN.T[0][j].M[h].task1->policy1, CN.T[0][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[0][j].M[h].task1->link1!='\0')
  CN.T[0][j].M[h].task1 = CN.T[0][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].init_task1;
          if(CN.T[1][j].M[h].not1>0) 
          { //3
           for(l=0;l<=CN.T[1][j].M[h].not1-1;l++)
          { // 4
          w = atol(CN.T[1][j].M[h].task1->PID1);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN.T[1][j].M[h].task1->PID1, CN.T[1][j].M[h].task1->netflag1, CN.T[1][j].M[h].task1->memsze1, CN.T[1][j].M[h].task1->time1, prio, CN.T[1][j].M[h].task1->policy1, CN.T[1][j].M[h].task1->name1); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN.T[1][j].M[h].task1->link1!='\0')
  CN.T[1][j].M[h].task1 = CN.T[1][j].M[h].task1->link1;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_cls'\n\n", opt);
}    
else printf("\n\n INVALID ENTRY!!!\n\n");
return (1);
} // function is closed
int csl()
{
    char i;
    FILE *F;
    F = fopen("input2.txt","r");
    fscanf(F, "%c", &i);
    ufs_csl(i);
    return (1);
}
ufs_csl(char opt)
    {  //  opt option for deciding purpose // lgfle stored logfile          
int i, k, len, len1, j, l, temp1, prio, n, a, m, b, temp2, wg, h, non, pol1, pol2, v, g, not9=0;
long int w;
struct task_struct_csl
{   
    char PID2[15];
    char memsze2[10];
    char name2[50];
    char policy2[15];
    int time2;  // burst time in mins
    int netflag2;
    struct task_struct_csl *link2;
};
struct time_csl
    {
            struct task_struct_csl *task2, *init_task2, *Q2;
            int not2, flag2;
    };
struct mem_csl
    {
            struct time_csl T1[60];
    };
struct conn_csl
       {
            struct mem_csl M1[2][100];
       };
struct conn_csl CN1;
       float q, f;
       char C[15];       // non = number of nodes(mult. of 100 and 40)
       FILE *f1;
           // lgfle has output of “sudo netstat –p”
        
       i = ((maxmem+1)*(maxtme+1)); 
       if(i<6000) non = 2*i;
       else non = 12000;   // wg is for net weight
       pol1 = SCHED_FIFO;  // wg1 for mem weight, wg2 for normal task weight
       pol2 = SCHED_RR;
       for(i=0;i<=maxmem;i++)
       {
           for(j=0;j<=maxtme;j++)
           {
             CN1.M1[0][i].T1[j].not2 = 0;
             CN1.M1[1][i].T1[j].not2 = 0;
             CN1.M1[0][i].T1[j].flag2 = 0;
             CN1.M1[1][i].T1[j].flag2 = 0;
           }
       }
       len=0;
       l=0;
       if(non>=40) 
       {
          temp1 = non/40;
          f = non/40.00;
          if(f-temp1>0.5) temp1 = temp1+1;
       }
       else temp1 = 1;
       if(non>=10) 
       {
          temp2 = non/10;
          f = non/10.00;
          if(f-temp2>0.5) temp2 = temp2+1;
       }
       else temp2 = 1;
       wg =0;
       task = init_task; 
       while(1)
       {
           i = task->netflag;
           k = task->time;
           j = atoi(task->memsze);
           if(j>99) j=99;
           if(k>59) k=59;
           CN1.M1[i][j].T1[k].task2 = (struct task_struct_csl*)malloc(sizeof(struct task_struct_csl));
           CN1.M1[i][j].T1[k].task2->link2 = '\0';
           l = CN1.M1[i][j].T1[k].not2;
           strcpy(CN1.M1[i][j].T1[k].task2->PID2, task->PID);
           strcpy(CN1.M1[i][j].T1[k].task2->memsze2, task->memsze);
           strcpy(CN1.M1[i][j].T1[k].task2->name2, task->name);
       strcpy(CN1.M1[i][j].T1[k].task2->policy2, task->policy);              
       CN1.M1[i][j].T1[k].task2->time2 = task->time;
       CN1.M1[i][j].T1[k].task2->netflag2 = i;      
       l++;
       CN1.M1[i][j].T1[k].not2 = l;
       if(CN1.M1[i][j].T1[k].flag2==0) CN1.M1[i][j].T1[k].init_task2 = CN1.M1[i][j].T1[k].task2;
       if(CN1.M1[i][j].T1[k].flag2>0) CN1.M1[i][j].T1[k].Q2->link2 = CN1.M1[i][j].T1[k].task2;
       CN1.M1[i][j].T1[k].flag2++;
       CN1.M1[i][j].T1[k].Q2 = CN1.M1[i][j].T1[k].task2;
       if(task->link!='\0')
       task = task->link;
       if(wg==1) break;
       if(task->link=='\0') wg=1;
       }    // closing task loop
    a=-20;
    b=-20;  
    v=0;  // for real time processes 
    n=0; // for normal processes
    if(opt=='1')    // internet is preferred, mem from low to high
    {  // 1
      f1 = fopen("output1_csl.txt","w");
     fprintf(f1, "\n1 - Internet + light + small tasks\n2 - Normal + light + small tasks\n3 - Internet + heavy + small tasks\n4 - Normal + heavy + small tasks\n5 - Internet + light + large tasks\n6 - Normal + light + large tasks\n7 - Internet + heavy + large tasks\n8 - Normal + heavy + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].init_task2;
          if(CN1.M1[1][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[1][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[1][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[1][j].T1[h].task2->PID2, CN1.M1[1][j].T1[h].task2->netflag2, CN1.M1[1][j].T1[h].task2->memsze2, CN1.M1[1][j].T1[h].task2->time2, prio, CN1.M1[1][j].T1[h].task2->policy2, CN1.M1[1][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[1][j].T1[h].task2->link2!='\0')
  CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].init_task2;
          if(CN1.M1[0][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[0][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[0][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[0][j].T1[h].task2->PID2, CN1.M1[0][j].T1[h].task2->netflag2, CN1.M1[0][j].T1[h].task2->memsze2, CN1.M1[0][j].T1[h].task2->time2, prio, CN1.M1[0][j].T1[h].task2->policy2, CN1.M1[0][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[0][j].T1[h].task2->link2!='\0')
  CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_csl'\n\n", opt);
    } // cl 1
    else if(opt=='2')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output2_csl.txt","w");
     fprintf(f1, "\n1 - Internet + light + small tasks\n2 - Normal + light + small tasks\n3 - Internet + heavy + small tasks\n4 - Normal + heavy + small tasks\n5 - Internet + light + large tasks\n6 - Normal + light + large tasks\n7 - Internet + heavy + large tasks\n8 - Normal + heavy + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].init_task2;
          if(CN1.M1[0][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[0][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[0][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[0][j].T1[h].task2->PID2, CN1.M1[0][j].T1[h].task2->netflag2, CN1.M1[0][j].T1[h].task2->memsze2, CN1.M1[0][j].T1[h].task2->time2, prio, CN1.M1[0][j].T1[h].task2->policy2, CN1.M1[0][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[0][j].T1[h].task2->link2!='\0')
  CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].init_task2;
          if(CN1.M1[1][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[1][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[1][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[1][j].T1[h].task2->PID2, CN1.M1[1][j].T1[h].task2->netflag2, CN1.M1[1][j].T1[h].task2->memsze2, CN1.M1[1][j].T1[h].task2->time2, prio, CN1.M1[1][j].T1[h].task2->policy2, CN1.M1[1][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[1][j].T1[h].task2->link2!='\0')
  CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_csl'\n\n", opt);
    } // cl 1
    else if(opt=='3')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output3_csl.txt","w");
     fprintf(f1, "\n1 - Internet + light + small tasks\n2 - Normal + light + small tasks\n3 - Internet + heavy + small tasks\n4 - Normal + heavy + small tasks\n5 - Internet + light + large tasks\n6 - Normal + light + large tasks\n7 - Internet + heavy + large tasks\n8 - Normal + heavy + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].init_task2;
          if(CN1.M1[1][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[1][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[1][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[1][j].T1[h].task2->PID2, CN1.M1[1][j].T1[h].task2->netflag2, CN1.M1[1][j].T1[h].task2->memsze2, CN1.M1[1][j].T1[h].task2->time2, prio, CN1.M1[1][j].T1[h].task2->policy2, CN1.M1[1][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[1][j].T1[h].task2->link2!='\0')
  CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].init_task2;
          if(CN1.M1[0][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[0][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[0][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[0][j].T1[h].task2->PID2, CN1.M1[0][j].T1[h].task2->netflag2, CN1.M1[0][j].T1[h].task2->memsze2, CN1.M1[0][j].T1[h].task2->time2, prio, CN1.M1[0][j].T1[h].task2->policy2, CN1.M1[0][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[0][j].T1[h].task2->link2!='\0')
  CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_csl'\n\n", opt);
    } // cl 1
    else if(opt=='4') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output4_csl.txt","w");
     fprintf(f1, "\n1 - Internet + light + small tasks\n2 - Normal + light + small tasks\n3 - Internet + heavy + small tasks\n4 - Normal + heavy + small tasks\n5 - Internet + light + large tasks\n6 - Normal + light + large tasks\n7 - Internet + heavy + large tasks\n8 - Normal + heavy + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].init_task2;
          if(CN1.M1[0][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[0][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[0][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[0][j].T1[h].task2->PID2, CN1.M1[0][j].T1[h].task2->netflag2, CN1.M1[0][j].T1[h].task2->memsze2, CN1.M1[0][j].T1[h].task2->time2, prio, CN1.M1[0][j].T1[h].task2->policy2, CN1.M1[0][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[0][j].T1[h].task2->link2!='\0')
  CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].init_task2;
          if(CN1.M1[1][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[1][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[1][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[1][j].T1[h].task2->PID2, CN1.M1[1][j].T1[h].task2->netflag2, CN1.M1[1][j].T1[h].task2->memsze2, CN1.M1[1][j].T1[h].task2->time2, prio, CN1.M1[1][j].T1[h].task2->policy2, CN1.M1[1][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[1][j].T1[h].task2->link2!='\0')
  CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_csl'\n\n", opt);
    } // cl 1
else if(opt=='5')   
    {  // 1
      f1 = fopen("output5_csl.txt","w");
     fprintf(f1, "\n1 - Internet + light + small tasks\n2 - Normal + light + small tasks\n3 - Internet + heavy + small tasks\n4 - Normal + heavy + small tasks\n5 - Internet + light + large tasks\n6 - Normal + light + large tasks\n7 - Internet + heavy + large tasks\n8 - Normal + heavy + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].init_task2;
          if(CN1.M1[1][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[1][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[1][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[1][j].T1[h].task2->PID2, CN1.M1[1][j].T1[h].task2->netflag2, CN1.M1[1][j].T1[h].task2->memsze2, CN1.M1[1][j].T1[h].task2->time2, prio, CN1.M1[1][j].T1[h].task2->policy2, CN1.M1[1][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[1][j].T1[h].task2->link2!='\0')
  CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].init_task2;
          if(CN1.M1[0][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[0][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[0][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[0][j].T1[h].task2->PID2, CN1.M1[0][j].T1[h].task2->netflag2, CN1.M1[0][j].T1[h].task2->memsze2, CN1.M1[0][j].T1[h].task2->time2, prio, CN1.M1[0][j].T1[h].task2->policy2, CN1.M1[0][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[0][j].T1[h].task2->link2!='\0')
  CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_csl'\n\n", opt);
    } // cl 1
    else if(opt=='6')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output6_csl.txt","w");
     fprintf(f1, "\n1 - Internet + light + small tasks\n2 - Normal + light + small tasks\n3 - Internet + heavy + small tasks\n4 - Normal + heavy + small tasks\n5 - Internet + light + large tasks\n6 - Normal + light + large tasks\n7 - Internet + heavy + large tasks\n8 - Normal + heavy + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].init_task2;
          if(CN1.M1[0][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[0][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[0][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[0][j].T1[h].task2->PID2, CN1.M1[0][j].T1[h].task2->netflag2, CN1.M1[0][j].T1[h].task2->memsze2, CN1.M1[0][j].T1[h].task2->time2, prio, CN1.M1[0][j].T1[h].task2->policy2, CN1.M1[0][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[0][j].T1[h].task2->link2!='\0')
  CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].init_task2;
          if(CN1.M1[1][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[1][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[1][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[1][j].T1[h].task2->PID2, CN1.M1[1][j].T1[h].task2->netflag2, CN1.M1[1][j].T1[h].task2->memsze2, CN1.M1[1][j].T1[h].task2->time2, prio, CN1.M1[1][j].T1[h].task2->policy2, CN1.M1[1][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[1][j].T1[h].task2->link2!='\0')
  CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_csl'\n\n", opt);
    } // cl 1
    else if(opt=='7')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output7_csl.txt","w");
     fprintf(f1, "\n1 - Internet + light + small tasks\n2 - Normal + light + small tasks\n3 - Internet + heavy + small tasks\n4 - Normal + heavy + small tasks\n5 - Internet + light + large tasks\n6 - Normal + light + large tasks\n7 - Internet + heavy + large tasks\n8 - Normal + heavy + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].init_task2;
          if(CN1.M1[1][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[1][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[1][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[1][j].T1[h].task2->PID2, CN1.M1[1][j].T1[h].task2->netflag2, CN1.M1[1][j].T1[h].task2->memsze2, CN1.M1[1][j].T1[h].task2->time2, prio, CN1.M1[1][j].T1[h].task2->policy2, CN1.M1[1][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[1][j].T1[h].task2->link2!='\0')
  CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].init_task2;
          if(CN1.M1[0][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[0][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[0][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[0][j].T1[h].task2->PID2, CN1.M1[0][j].T1[h].task2->netflag2, CN1.M1[0][j].T1[h].task2->memsze2, CN1.M1[0][j].T1[h].task2->time2, prio, CN1.M1[0][j].T1[h].task2->policy2, CN1.M1[0][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[0][j].T1[h].task2->link2!='\0')
  CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_csl'\n\n", opt);
    } // cl 1
    else if(opt=='8') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output8_csl.txt","w");
     fprintf(f1, "\n1 - Internet + light + small tasks\n2 - Normal + light + small tasks\n3 - Internet + heavy + small tasks\n4 - Normal + heavy + small tasks\n5 - Internet + light + large tasks\n6 - Normal + light + large tasks\n7 - Internet + heavy + large tasks\n8 - Normal + heavy + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].init_task2;
          if(CN1.M1[0][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[0][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[0][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[0][j].T1[h].task2->PID2, CN1.M1[0][j].T1[h].task2->netflag2, CN1.M1[0][j].T1[h].task2->memsze2, CN1.M1[0][j].T1[h].task2->time2, prio, CN1.M1[0][j].T1[h].task2->policy2, CN1.M1[0][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[0][j].T1[h].task2->link2!='\0')
  CN1.M1[0][j].T1[h].task2 = CN1.M1[0][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].init_task2;
          if(CN1.M1[1][j].T1[h].not2>0) 
          { //3
           for(l=0;l<=CN1.M1[1][j].T1[h].not2-1;l++)
          { // 4
          w = atol(CN1.M1[1][j].T1[h].task2->PID2);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", CN1.M1[1][j].T1[h].task2->PID2, CN1.M1[1][j].T1[h].task2->netflag2, CN1.M1[1][j].T1[h].task2->memsze2, CN1.M1[1][j].T1[h].task2->time2, prio, CN1.M1[1][j].T1[h].task2->policy2, CN1.M1[1][j].T1[h].task2->name2); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(CN1.M1[1][j].T1[h].task2->link2!='\0')
  CN1.M1[1][j].T1[h].task2 = CN1.M1[1][j].T1[h].task2->link2;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_csl'\n\n", opt);
}    
else printf("\n\n INVALID ENTRY!!!\n\n");
return (1);
} // function is closed
int lcs()
{
    char i;
    FILE *F;    
    F = fopen("input2.txt","r");
    fscanf(F, "%c", &i);
    ufs_lcs(i);
    return (1);
}
int ufs_lcs(char opt)
    {  //  opt option for deciding purpose // lgfle stored logfile          
struct task_struct_lcs
{   
    char PID3[15];
    char memsze3[10];
    char name3[50];
    char policy3[15];
    int time3;  // burst time in mins
    int netflag3;
    struct task_struct_lcs *link3;
};
struct mem_lcs
    {
            struct task_struct_lcs *task3, *init_task3, *Q3;
            int not3, flag3;
    };
struct conn_lcs
    {
            struct mem_lcs M2[100];
    };
struct time_lcs
       {
            struct conn_lcs CN2[60][2];
       };
struct time_lcs T2;
int i, k, len, len1, j, l, temp1, prio, n, a, m, b, temp2, wg, h, non, pol1, pol2, v, g, not9=0;
long int w;
       float q, f;
       char C[15];       // non = number of nodes(mult. of 100 and 40)
       FILE *f1;
           // lgfle has output of “sudo netstat –p”
        
       i = ((maxmem+1)*(maxtme+1)); 
       if(i<6000) non = 2*i;
       else non = 12000;   // wg is for net weight
       pol1 = SCHED_FIFO;  // wg1 for mem weight, wg2 for normal task weight
       pol2 = SCHED_RR;
       for(i=0;i<=maxtme;i++)
       {
           for(j=0;j<=maxmem;j++)
           {
             T2.CN2[i][0].M2[j].not3 = 0;
             T2.CN2[i][1].M2[j].not3 = 0;
             T2.CN2[i][0].M2[j].flag3 = 0;
             T2.CN2[i][1].M2[j].flag3 = 0;
           }
       }
       len=0;
       l=0;
       if(non>=40) 
       {
          temp1 = non/40;
          f = non/40.00;
          if(f-temp1>0.5) temp1 = temp1+1;
       }
       else temp1 = 1;
       if(non>=10) 
       {
          temp2 = non/10;
          f = non/10.00;
          if(f-temp2>0.5) temp2 = temp2+1;
       }
       else temp2 = 1;
       wg =0;
       task = init_task; 
       while(1)
       {
           i = task->netflag;
           k = task->time;
           j = atoi(task->memsze);
           if(j>99) j=99;
           if(k>59) k=59;
           T2.CN2[k][i].M2[j].task3 = (struct task_struct_lcs*)malloc(sizeof(struct task_struct_lcs));
           T2.CN2[k][i].M2[j].task3->link3 = '\0';
           l = T2.CN2[k][i].M2[j].not3;
           strcpy(T2.CN2[k][i].M2[j].task3->PID3, task->PID);
           strcpy(T2.CN2[k][i].M2[j].task3->memsze3, task->memsze);
           strcpy(T2.CN2[k][i].M2[j].task3->name3, task->name);
       strcpy(T2.CN2[k][i].M2[j].task3->policy3, task->policy);              
       T2.CN2[k][i].M2[j].task3->time3 = task->time;
       T2.CN2[k][i].M2[j].task3->netflag3 = i;      
       l++;
       T2.CN2[k][i].M2[j].not3 = l;
       if(T2.CN2[k][i].M2[j].flag3==0) T2.CN2[k][i].M2[j].init_task3 = T2.CN2[k][i].M2[j].task3;
       if(T2.CN2[k][i].M2[j].flag3>0) T2.CN2[k][i].M2[j].Q3->link3 = T2.CN2[k][i].M2[j].task3;
       T2.CN2[k][i].M2[j].flag3++;
       T2.CN2[k][i].M2[j].Q3 = T2.CN2[k][i].M2[j].task3;
       if(task->link!='\0')
       task = task->link;
       if(wg==1) break;
       if(task->link=='\0') wg=1;
       }    // closing task loop
    a=-20;
    b=-20;  
    v=0;  // for real time processes 
    n=0; // for normal processes
    if(opt=='1')    // internet is preferred, mem from low to high
    {  // 1
      f1 = fopen("output1_lcs.txt","w");
     fprintf(f1, "\n1 - Small + internet + light tasks\n2 - Small + normal + light tasks\n3 - Small + internet + heavy tasks\n4 - Small + normal + heavy tasks\n5 - Large + internet + light tasks\n6 - Large + normal + light tasks\n7 - Large + internet + heavy tasks\n8 - Large + normal + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].init_task3;
          if(T2.CN2[j][1].M2[h].not3>0) 
          { //3
           for(l=0;l<=T2.CN2[j][1].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][1].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][1].M2[h].task3->PID3, T2.CN2[j][1].M2[h].task3->netflag3, T2.CN2[j][1].M2[h].task3->memsze3, T2.CN2[j][1].M2[h].task3->time3, prio, T2.CN2[j][1].M2[h].task3->policy3, T2.CN2[j][1].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][1].M2[h].task3->link3!='\0')
  T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].init_task3;
          if(T2.CN2[j][0].M2[h].not3>0) 
          { //3
             for(l=0;l<=T2.CN2[j][0].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][0].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][0].M2[h].task3->PID3, T2.CN2[j][0].M2[h].task3->netflag3, T2.CN2[j][0].M2[h].task3->memsze3, T2.CN2[j][0].M2[h].task3->time3, prio, T2.CN2[j][0].M2[h].task3->policy3, T2.CN2[j][0].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][0].M2[h].task3->link3!='\0')
  T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lcs'\n\n", opt);
    } // cl 1
    else if(opt=='2')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output2_lcs.txt","w");
     fprintf(f1, "\n1 - Small + internet + light tasks\n2 - Small + normal + light tasks\n3 - Small + internet + heavy tasks\n4 - Small + normal + heavy tasks\n5 - Large + internet + light tasks\n6 - Large + normal + light tasks\n7 - Large + internet + heavy tasks\n8 - Large + normal + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].init_task3;
          if(T2.CN2[j][0].M2[h].not3>0) 
          { //3
             for(l=0;l<=T2.CN2[j][0].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][0].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][0].M2[h].task3->PID3, T2.CN2[j][0].M2[h].task3->netflag3, T2.CN2[j][0].M2[h].task3->memsze3, T2.CN2[j][0].M2[h].task3->time3, prio, T2.CN2[j][0].M2[h].task3->policy3, T2.CN2[j][0].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][0].M2[h].task3->link3!='\0')
  T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].init_task3;
          if(T2.CN2[j][1].M2[h].not3>0) 
          { //3
           for(l=0;l<=T2.CN2[j][1].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][1].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][1].M2[h].task3->PID3, T2.CN2[j][1].M2[h].task3->netflag3, T2.CN2[j][1].M2[h].task3->memsze3, T2.CN2[j][1].M2[h].task3->time3, prio, T2.CN2[j][1].M2[h].task3->policy3, T2.CN2[j][1].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][1].M2[h].task3->link3!='\0')
  T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lcs'\n\n", opt);
    } // cl 1
    else if(opt=='3')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output3_lcs.txt","w");
     fprintf(f1, "\n1 - Small + internet + light tasks\n2 - Small + normal + light tasks\n3 - Small + internet + heavy tasks\n4 - Small + normal + heavy tasks\n5 - Large + internet + light tasks\n6 - Large + normal + light tasks\n7 - Large + internet + heavy tasks\n8 - Large + normal + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].init_task3;
          if(T2.CN2[j][1].M2[h].not3>0) 
          { //3
           for(l=0;l<=T2.CN2[j][1].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][1].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][1].M2[h].task3->PID3, T2.CN2[j][1].M2[h].task3->netflag3, T2.CN2[j][1].M2[h].task3->memsze3, T2.CN2[j][1].M2[h].task3->time3, prio, T2.CN2[j][1].M2[h].task3->policy3, T2.CN2[j][1].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][1].M2[h].task3->link3!='\0')
  T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].init_task3;
          if(T2.CN2[j][0].M2[h].not3>0) 
          { //3
             for(l=0;l<=T2.CN2[j][0].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][0].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][0].M2[h].task3->PID3, T2.CN2[j][0].M2[h].task3->netflag3, T2.CN2[j][0].M2[h].task3->memsze3, T2.CN2[j][0].M2[h].task3->time3, prio, T2.CN2[j][0].M2[h].task3->policy3, T2.CN2[j][0].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][0].M2[h].task3->link3!='\0')
  T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lcs'\n\n", opt);
    } // cl 1
    else if(opt=='4') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output4_lcs.txt","w");
     fprintf(f1, "\n1 - Small + internet + light tasks\n2 - Small + normal + light tasks\n3 - Small + internet + heavy tasks\n4 - Small + normal + heavy tasks\n5 - Large + internet + light tasks\n6 - Large + normal + light tasks\n7 - Large + internet + heavy tasks\n8 - Large + normal + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].init_task3;
          if(T2.CN2[j][0].M2[h].not3>0) 
          { //3
             for(l=0;l<=T2.CN2[j][0].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][0].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][0].M2[h].task3->PID3, T2.CN2[j][0].M2[h].task3->netflag3, T2.CN2[j][0].M2[h].task3->memsze3, T2.CN2[j][0].M2[h].task3->time3, prio, T2.CN2[j][0].M2[h].task3->policy3, T2.CN2[j][0].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][0].M2[h].task3->link3!='\0')
  T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].init_task3;
          if(T2.CN2[j][1].M2[h].not3>0) 
          { //3
           for(l=0;l<=T2.CN2[j][1].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][1].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][1].M2[h].task3->PID3, T2.CN2[j][1].M2[h].task3->netflag3, T2.CN2[j][1].M2[h].task3->memsze3, T2.CN2[j][1].M2[h].task3->time3, prio, T2.CN2[j][1].M2[h].task3->policy3, T2.CN2[j][1].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][1].M2[h].task3->link3!='\0')
  T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lcs'\n\n", opt);
    } // cl 1
else if(opt=='5')   
    {  // 1
      f1 = fopen("output5_lcs.txt","w");
     fprintf(f1, "\n1 - Small + internet + light tasks\n2 - Small + normal + light tasks\n3 - Small + internet + heavy tasks\n4 - Small + normal + heavy tasks\n5 - Large + internet + light tasks\n6 - Large + normal + light tasks\n7 - Large + internet + heavy tasks\n8 - Large + normal + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].init_task3;
          if(T2.CN2[j][1].M2[h].not3>0) 
          { //3
           for(l=0;l<=T2.CN2[j][1].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][1].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][1].M2[h].task3->PID3, T2.CN2[j][1].M2[h].task3->netflag3, T2.CN2[j][1].M2[h].task3->memsze3, T2.CN2[j][1].M2[h].task3->time3, prio, T2.CN2[j][1].M2[h].task3->policy3, T2.CN2[j][1].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][1].M2[h].task3->link3!='\0')
  T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].init_task3;
          if(T2.CN2[j][0].M2[h].not3>0) 
          { //3
             for(l=0;l<=T2.CN2[j][0].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][0].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][0].M2[h].task3->PID3, T2.CN2[j][0].M2[h].task3->netflag3, T2.CN2[j][0].M2[h].task3->memsze3, T2.CN2[j][0].M2[h].task3->time3, prio, T2.CN2[j][0].M2[h].task3->policy3, T2.CN2[j][0].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][0].M2[h].task3->link3!='\0')
  T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lcs'\n\n", opt);
    } // cl 1
    else if(opt=='6')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output6_lcs.txt","w");
     fprintf(f1, "\n1 - Small + internet + light tasks\n2 - Small + normal + light tasks\n3 - Small + internet + heavy tasks\n4 - Small + normal + heavy tasks\n5 - Large + internet + light tasks\n6 - Large + normal + light tasks\n7 - Large + internet + heavy tasks\n8 - Large + normal + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].init_task3;
          if(T2.CN2[j][0].M2[h].not3>0) 
          { //3
             for(l=0;l<=T2.CN2[j][0].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][0].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][0].M2[h].task3->PID3, T2.CN2[j][0].M2[h].task3->netflag3, T2.CN2[j][0].M2[h].task3->memsze3, T2.CN2[j][0].M2[h].task3->time3, prio, T2.CN2[j][0].M2[h].task3->policy3, T2.CN2[j][0].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][0].M2[h].task3->link3!='\0')
  T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].init_task3;
          if(T2.CN2[j][1].M2[h].not3>0) 
          { //3
           for(l=0;l<=T2.CN2[j][1].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][1].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][1].M2[h].task3->PID3, T2.CN2[j][1].M2[h].task3->netflag3, T2.CN2[j][1].M2[h].task3->memsze3, T2.CN2[j][1].M2[h].task3->time3, prio, T2.CN2[j][1].M2[h].task3->policy3, T2.CN2[j][1].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][1].M2[h].task3->link3!='\0')
  T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lcs'\n\n", opt);
    } // cl 1
    else if(opt=='7')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output7_lcs.txt","w");
     fprintf(f1, "\n1 - Small + internet + light tasks\n2 - Small + normal + light tasks\n3 - Small + internet + heavy tasks\n4 - Small + normal + heavy tasks\n5 - Large + internet + light tasks\n6 - Large + normal + light tasks\n7 - Large + internet + heavy tasks\n8 - Large + normal + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].init_task3;
          if(T2.CN2[j][1].M2[h].not3>0) 
          { //3
           for(l=0;l<=T2.CN2[j][1].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][1].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][1].M2[h].task3->PID3, T2.CN2[j][1].M2[h].task3->netflag3, T2.CN2[j][1].M2[h].task3->memsze3, T2.CN2[j][1].M2[h].task3->time3, prio, T2.CN2[j][1].M2[h].task3->policy3, T2.CN2[j][1].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][1].M2[h].task3->link3!='\0')
  T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].init_task3;
          if(T2.CN2[j][0].M2[h].not3>0) 
          { //3
             for(l=0;l<=T2.CN2[j][0].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][0].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][0].M2[h].task3->PID3, T2.CN2[j][0].M2[h].task3->netflag3, T2.CN2[j][0].M2[h].task3->memsze3, T2.CN2[j][0].M2[h].task3->time3, prio, T2.CN2[j][0].M2[h].task3->policy3, T2.CN2[j][0].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][0].M2[h].task3->link3!='\0')
  T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lcs'\n\n", opt);
    } // cl 1
    else if(opt=='8') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output8_lcs.txt","w");
     fprintf(f1, "\n1 - Small + internet + light tasks\n2 - Small + normal + light tasks\n3 - Small + internet + heavy tasks\n4 - Small + normal + heavy tasks\n5 - Large + internet + light tasks\n6 - Large + normal + light tasks\n7 - Large + internet + heavy tasks\n8 - Large + normal + heavy tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].init_task3;
          if(T2.CN2[j][0].M2[h].not3>0) 
          { //3
             for(l=0;l<=T2.CN2[j][0].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][0].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][0].M2[h].task3->PID3, T2.CN2[j][0].M2[h].task3->netflag3, T2.CN2[j][0].M2[h].task3->memsze3, T2.CN2[j][0].M2[h].task3->time3, prio, T2.CN2[j][0].M2[h].task3->policy3, T2.CN2[j][0].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][0].M2[h].task3->link3!='\0')
  T2.CN2[j][0].M2[h].task3 = T2.CN2[j][0].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].init_task3;
          if(T2.CN2[j][1].M2[h].not3>0) 
          { //3
           for(l=0;l<=T2.CN2[j][1].M2[h].not3-1;l++)
          { // 4
          w = atol(T2.CN2[j][1].M2[h].task3->PID3);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T2.CN2[j][1].M2[h].task3->PID3, T2.CN2[j][1].M2[h].task3->netflag3, T2.CN2[j][1].M2[h].task3->memsze3, T2.CN2[j][1].M2[h].task3->time3, prio, T2.CN2[j][1].M2[h].task3->policy3, T2.CN2[j][1].M2[h].task3->name3); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T2.CN2[j][1].M2[h].task3->link3!='\0')
  T2.CN2[j][1].M2[h].task3 = T2.CN2[j][1].M2[h].task3->link3;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lcs'\n\n", opt);
}    
else printf("\n\n INVALID ENTRY!!!\n\n");
return (1);
} // function is closed
int lsc()
{
    char i;
    FILE *F;    
    F = fopen("input2.txt","r");
    fscanf(F, "%c", &i);
    ufs_lsc(i);
    return (1);
}
int ufs_lsc(char opt)
    {  //  opt option for deciding purpose // lgfle stored logfile          
struct task_struct_lsc
{   
    char PID4[15];
    char memsze4[10];
    char name4[50];
    char policy4[15];
    int time4;  // burst time in mins
    int netflag4;
    struct task_struct_lsc *link4;
};
struct conn_lsc
    {
            struct task_struct_lsc *task4, *init_task4, *Q4;
            int not4, flag4;
    };
struct mem_lsc
    {
            struct conn_lsc CN3[2];
    };
struct time_lsc
       {
            struct mem_lsc M3[60][100];
       };
struct time_lsc T3;
int i, k, len, len1, j, l, temp1, prio, n, a, m, b, temp2, wg, h, non, pol1, pol2, v, g, not9=0;
long int w;
       float q, f;
       char C[15];       // non = number of nodes(mult. of 100 and 40)
       FILE *f1;
           // lgfle has output of “sudo netstat –p”
        
       i = ((maxmem+1)*(maxtme+1)); 
       if(i<6000) non = 2*i;
       else non = 12000;   // wg is for net weight
       pol1 = SCHED_FIFO;  // wg1 for mem weight, wg2 for normal task weight
       pol2 = SCHED_RR;
       for(i=0;i<=maxtme;i++)
       {
           for(j=0;j<=maxmem;j++)
           {
             T3.M3[i][j].CN3[0].not4 = 0;
             T3.M3[j][j].CN3[1].not4 = 0;
             T3.M3[i][j].CN3[1].flag4 = 0;
             T3.M3[i][j].CN3[0].flag4 = 0;
           }
       }
       len=0;
       l=0;
       if(non>=40) 
       {
          temp1 = non/40;
          f = non/40.00;
          if(f-temp1>0.5) temp1 = temp1+1;
       }
       else temp1 = 1;
       if(non>=10) 
       {
          temp2 = non/10;
          f = non/10.00;
          if(f-temp2>0.5) temp2 = temp2+1;
       }
       else temp2 = 1;
       wg =0;
       task = init_task; 
       while(1)
       {
           i = task->netflag;
           k = task->time;
           j = atoi(task->memsze);
           if(j>99) j=99;
           if(k>59) k=59;
           T3.M3[k][j].CN3[i].task4 = (struct task_struct_lsc*)malloc(sizeof(struct task_struct_lsc));
           T3.M3[k][j].CN3[i].task4->link4 = '\0';
           l = T3.M3[k][j].CN3[i].not4;
           strcpy(T3.M3[k][j].CN3[i].task4->PID4, task->PID);
           strcpy(T3.M3[k][j].CN3[i].task4->memsze4, task->memsze);
           strcpy(T3.M3[k][j].CN3[i].task4->name4, task->name);
       strcpy(T3.M3[k][j].CN3[i].task4->policy4, task->policy);              
       T3.M3[k][j].CN3[i].task4->time4 = task->time;
       T3.M3[k][j].CN3[i].task4->netflag4 = i;      
       l++;
       T3.M3[k][j].CN3[i].not4 = l;
       if(T3.M3[k][j].CN3[i].flag4==0) T3.M3[k][j].CN3[i].init_task4 = T3.M3[k][j].CN3[i].task4;
       if(T3.M3[k][j].CN3[i].flag4>0) T3.M3[k][j].CN3[i].Q4->link4 = T3.M3[k][j].CN3[i].task4;
       T3.M3[k][j].CN3[i].flag4++;
       T3.M3[k][j].CN3[i].Q4 = T3.M3[k][j].CN3[i].task4;
       if(task->link!='\0')
       task = task->link;
       if(wg==1) break;
       if(task->link=='\0') wg=1;
       }    // closing task loop
    a=-20;
    b=-20;  
    v=0;  // for real time processes 
    n=0; // for normal processes
    if(opt=='1')    // internet is preferred, mem from low to high
    {  // 1
      f1 = fopen("output1_lsc.txt","w");
     fprintf(f1, "\n1 - Small + light + internet tasks\n2 - Small + light + normal tasks\n3 - Small + heavy + internet tasks\n4 - Small + heavy + normal tasks\n5 - Large + light + internet tasks\n6 - Large + light + normal tasks\n7 - Large + heavy + internet tasks\n8 - Large + heavy + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].init_task4;
          if(T3.M3[j][h].CN3[1].not4>0) 
          { //3
           for(l=0;l<=T3.M3[j][h].CN3[1].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[1].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[1].task4->PID4, T3.M3[j][h].CN3[1].task4->netflag4, T3.M3[j][h].CN3[1].task4->memsze4, T3.M3[j][h].CN3[1].task4->time4, prio, T3.M3[j][h].CN3[1].task4->policy4, T3.M3[j][h].CN3[1].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[1].task4->link4!='\0')
  T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].init_task4;
          if(T3.M3[j][h].CN3[0].not4>0) 
          { //3
             for(l=0;l<=T3.M3[j][h].CN3[0].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[0].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[0].task4->PID4, T3.M3[j][h].CN3[0].task4->netflag4, T3.M3[j][h].CN3[0].task4->memsze4, T3.M3[j][h].CN3[0].task4->time4, prio, T3.M3[j][h].CN3[0].task4->policy4, T3.M3[j][h].CN3[0].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[0].task4->link4!='\0')
  T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lsc'\n\n", opt);
    } // cl 1
    else if(opt=='2')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output2_lsc.txt","w");
     fprintf(f1, "\n1 - Small + light + internet tasks\n2 - Small + light + normal tasks\n3 - Small + heavy + internet tasks\n4 - Small + heavy + normal tasks\n5 - Large + light + internet tasks\n6 - Large + light + normal tasks\n7 - Large + heavy + internet tasks\n8 - Large + heavy + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].init_task4;
          if(T3.M3[j][h].CN3[0].not4>0) 
          { //3
             for(l=0;l<=T3.M3[j][h].CN3[0].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[0].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[0].task4->PID4, T3.M3[j][h].CN3[0].task4->netflag4, T3.M3[j][h].CN3[0].task4->memsze4, T3.M3[j][h].CN3[0].task4->time4, prio, T3.M3[j][h].CN3[0].task4->policy4, T3.M3[j][h].CN3[0].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[0].task4->link4!='\0')
  T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].init_task4;
          if(T3.M3[j][h].CN3[1].not4>0) 
          { //3
           for(l=0;l<=T3.M3[j][h].CN3[1].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[1].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[1].task4->PID4, T3.M3[j][h].CN3[1].task4->netflag4, T3.M3[j][h].CN3[1].task4->memsze4, T3.M3[j][h].CN3[1].task4->time4, prio, T3.M3[j][h].CN3[1].task4->policy4, T3.M3[j][h].CN3[1].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[1].task4->link4!='\0')
  T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lsc'\n\n", opt);
    } // cl 1
    else if(opt=='3')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output3_lsc.txt","w");
     fprintf(f1, "\n1 - Small + light + internet tasks\n2 - Small + light + normal tasks\n3 - Small + heavy + internet tasks\n4 - Small + heavy + normal tasks\n5 - Large + light + internet tasks\n6 - Large + light + normal tasks\n7 - Large + heavy + internet tasks\n8 - Large + heavy + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].init_task4;
          if(T3.M3[j][h].CN3[1].not4>0) 
          { //3
           for(l=0;l<=T3.M3[j][h].CN3[1].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[1].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[1].task4->PID4, T3.M3[j][h].CN3[1].task4->netflag4, T3.M3[j][h].CN3[1].task4->memsze4, T3.M3[j][h].CN3[1].task4->time4, prio, T3.M3[j][h].CN3[1].task4->policy4, T3.M3[j][h].CN3[1].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[1].task4->link4!='\0')
  T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].init_task4;
          if(T3.M3[j][h].CN3[0].not4>0) 
          { //3
             for(l=0;l<=T3.M3[j][h].CN3[0].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[0].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[0].task4->PID4, T3.M3[j][h].CN3[0].task4->netflag4, T3.M3[j][h].CN3[0].task4->memsze4, T3.M3[j][h].CN3[0].task4->time4, prio, T3.M3[j][h].CN3[0].task4->policy4, T3.M3[j][h].CN3[0].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[0].task4->link4!='\0')
  T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lsc'\n\n", opt);
    } // cl 1
    else if(opt=='4') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output4_lsc.txt","w");
     fprintf(f1, "\n1 - Small + light + internet tasks\n2 - Small + light + normal tasks\n3 - Small + heavy + internet tasks\n4 - Small + heavy + normal tasks\n5 - Large + light + internet tasks\n6 - Large + light + normal tasks\n7 - Large + heavy + internet tasks\n8 - Large + heavy + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].init_task4;
          if(T3.M3[j][h].CN3[0].not4>0) 
          { //3
             for(l=0;l<=T3.M3[j][h].CN3[0].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[0].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[0].task4->PID4, T3.M3[j][h].CN3[0].task4->netflag4, T3.M3[j][h].CN3[0].task4->memsze4, T3.M3[j][h].CN3[0].task4->time4, prio, T3.M3[j][h].CN3[0].task4->policy4, T3.M3[j][h].CN3[0].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[0].task4->link4!='\0')
  T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxtme;j++)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].init_task4;
          if(T3.M3[j][h].CN3[1].not4>0) 
          { //3
           for(l=0;l<=T3.M3[j][h].CN3[1].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[1].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[1].task4->PID4, T3.M3[j][h].CN3[1].task4->netflag4, T3.M3[j][h].CN3[1].task4->memsze4, T3.M3[j][h].CN3[1].task4->time4, prio, T3.M3[j][h].CN3[1].task4->policy4, T3.M3[j][h].CN3[1].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[1].task4->link4!='\0')
  T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lsc'\n\n", opt);
    } // cl 1
else if(opt=='5')   
    {  // 1
      f1 = fopen("output5_lsc.txt","w");
     fprintf(f1, "\n1 - Small + light + internet tasks\n2 - Small + light + normal tasks\n3 - Small + heavy + internet tasks\n4 - Small + heavy + normal tasks\n5 - Large + light + internet tasks\n6 - Large + light + normal tasks\n7 - Large + heavy + internet tasks\n8 - Large + heavy + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].init_task4;
          if(T3.M3[j][h].CN3[1].not4>0) 
          { //3
           for(l=0;l<=T3.M3[j][h].CN3[1].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[1].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[1].task4->PID4, T3.M3[j][h].CN3[1].task4->netflag4, T3.M3[j][h].CN3[1].task4->memsze4, T3.M3[j][h].CN3[1].task4->time4, prio, T3.M3[j][h].CN3[1].task4->policy4, T3.M3[j][h].CN3[1].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[1].task4->link4!='\0')
  T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].init_task4;
          if(T3.M3[j][h].CN3[0].not4>0) 
          { //3
             for(l=0;l<=T3.M3[j][h].CN3[0].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[0].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[0].task4->PID4, T3.M3[j][h].CN3[0].task4->netflag4, T3.M3[j][h].CN3[0].task4->memsze4, T3.M3[j][h].CN3[0].task4->time4, prio, T3.M3[j][h].CN3[0].task4->policy4, T3.M3[j][h].CN3[0].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[0].task4->link4!='\0')
  T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lsc'\n\n", opt);
    } // cl 1
    else if(opt=='6')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output6_lsc.txt","w");
     fprintf(f1, "\n1 - Small + light + internet tasks\n2 - Small + light + normal tasks\n3 - Small + heavy + internet tasks\n4 - Small + heavy + normal tasks\n5 - Large + light + internet tasks\n6 - Large + light + normal tasks\n7 - Large + heavy + internet tasks\n8 - Large + heavy + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].init_task4;
          if(T3.M3[j][h].CN3[0].not4>0) 
          { //3
             for(l=0;l<=T3.M3[j][h].CN3[0].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[0].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[0].task4->PID4, T3.M3[j][h].CN3[0].task4->netflag4, T3.M3[j][h].CN3[0].task4->memsze4, T3.M3[j][h].CN3[0].task4->time4, prio, T3.M3[j][h].CN3[0].task4->policy4, T3.M3[j][h].CN3[0].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[0].task4->link4!='\0')
  T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=0;h<=maxmem;h++)
          {  // 2
          T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].init_task4;
          if(T3.M3[j][h].CN3[1].not4>0) 
          { //3
           for(l=0;l<=T3.M3[j][h].CN3[1].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[1].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[1].task4->PID4, T3.M3[j][h].CN3[1].task4->netflag4, T3.M3[j][h].CN3[1].task4->memsze4, T3.M3[j][h].CN3[1].task4->time4, prio, T3.M3[j][h].CN3[1].task4->policy4, T3.M3[j][h].CN3[1].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[1].task4->link4!='\0')
  T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lsc'\n\n", opt);
    } // cl 1
    else if(opt=='7')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output7_lsc.txt","w");
     fprintf(f1, "\n1 - Small + light + internet tasks\n2 - Small + light + normal tasks\n3 - Small + heavy + internet tasks\n4 - Small + heavy + normal tasks\n5 - Large + light + internet tasks\n6 - Large + light + normal tasks\n7 - Large + heavy + internet tasks\n8 - Large + heavy + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].init_task4;
          if(T3.M3[j][h].CN3[1].not4>0) 
          { //3
           for(l=0;l<=T3.M3[j][h].CN3[1].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[1].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[1].task4->PID4, T3.M3[j][h].CN3[1].task4->netflag4, T3.M3[j][h].CN3[1].task4->memsze4, T3.M3[j][h].CN3[1].task4->time4, prio, T3.M3[j][h].CN3[1].task4->policy4, T3.M3[j][h].CN3[1].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[1].task4->link4!='\0')
  T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].init_task4;
          if(T3.M3[j][h].CN3[0].not4>0) 
          { //3
             for(l=0;l<=T3.M3[j][h].CN3[0].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[0].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[0].task4->PID4, T3.M3[j][h].CN3[0].task4->netflag4, T3.M3[j][h].CN3[0].task4->memsze4, T3.M3[j][h].CN3[0].task4->time4, prio, T3.M3[j][h].CN3[0].task4->policy4, T3.M3[j][h].CN3[0].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[0].task4->link4!='\0')
  T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lsc'\n\n", opt);
    } // cl 1
    else if(opt=='8') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output8_lsc.txt","w");
     fprintf(f1, "\n1 - Small + light + internet tasks\n2 - Small + light + normal tasks\n3 - Small + heavy + internet tasks\n4 - Small + heavy + normal tasks\n5 - Large + light + internet tasks\n6 - Large + light + normal tasks\n7 - Large + heavy + internet tasks\n8 - Large + heavy + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].init_task4;
          if(T3.M3[j][h].CN3[0].not4>0) 
          { //3
             for(l=0;l<=T3.M3[j][h].CN3[0].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[0].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[0].task4->PID4, T3.M3[j][h].CN3[0].task4->netflag4, T3.M3[j][h].CN3[0].task4->memsze4, T3.M3[j][h].CN3[0].task4->time4, prio, T3.M3[j][h].CN3[0].task4->policy4, T3.M3[j][h].CN3[0].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[0].task4->link4!='\0')
  T3.M3[j][h].CN3[0].task4 = T3.M3[j][h].CN3[0].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxtme;j>=0;j--)
        { // 1
          for(h=maxmem;h>=0;h--)
          {  // 2
          T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].init_task4;
          if(T3.M3[j][h].CN3[1].not4>0) 
          { //3
           for(l=0;l<=T3.M3[j][h].CN3[1].not4-1;l++)
          { // 4
          w = atol(T3.M3[j][h].CN3[1].task4->PID4);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", T3.M3[j][h].CN3[1].task4->PID4, T3.M3[j][h].CN3[1].task4->netflag4, T3.M3[j][h].CN3[1].task4->memsze4, T3.M3[j][h].CN3[1].task4->time4, prio, T3.M3[j][h].CN3[1].task4->policy4, T3.M3[j][h].CN3[1].task4->name4); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(T3.M3[j][h].CN3[1].task4->link4!='\0')
  T3.M3[j][h].CN3[1].task4 = T3.M3[j][h].CN3[1].task4->link4;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_lsc'\n\n", opt);
}    
else printf("\n\n INVALID ENTRY!!!\n\n");
return (1);
} // function is closed
int slc()
{
    char i;
    FILE *F;    
    F = fopen("input2.txt","r");
    fscanf(F, "%c", &i);
    ufs_slc(i);
    return (1);
}
int ufs_slc(char opt)
    {  //  opt option for deciding purpose // lgfle stored logfile          
struct task_struct_slc
{   
    char PID5[15];
    char memsze5[10];
    char name5[50];
    char policy5[15];
    int time5;  // burst time in mins
    int netflag5;
    struct task_struct_slc *link5;
};
struct conn_slc
    {
            struct task_struct_slc *task5, *init_task5, *Q5;
            int not5, flag5;
    };
struct time_slc
    {
            struct conn_slc CN4[2];
    };
struct mem_slc
       {
            struct time_slc T4[100][60];
       };
struct mem_slc M4;
int i, k, len, len1, j, l, temp1, prio, n, a, m, b, temp2, wg, h, non, pol1, pol2, v, g, not9=0;
long int w;
       float q, f;
       char C[15];       // non = number of nodes(mult. of 100 and 40)
       FILE *f1;
           // lgfle has output of “sudo netstat –p”
        
       i = ((maxmem+1)*(maxtme+1)); 
       if(i<6000) non = 2*i;
       else non = 12000;   // wg is for net weight
       pol1 = SCHED_FIFO;  // wg1 for mem weight, wg2 for normal task weight
       pol2 = SCHED_RR;
       for(i=0;i<=maxmem;i++)
       {
           for(j=0;j<=maxtme;j++)
           {
             M4.T4[i][j].CN4[0].not5 = 0;
             M4.T4[i][j].CN4[1].not5 = 0;
             M4.T4[i][j].CN4[1].flag5 = 0;
             M4.T4[i][j].CN4[0].flag5 = 0;
           }
       }
       len=0;
       l=0;
       if(non>=40) 
       {
          temp1 = non/40;
          f = non/40.00;
          if(f-temp1>0.5) temp1 = temp1+1;
       }
       else temp1 = 1;
       if(non>=10) 
       {
          temp2 = non/10;
          f = non/10.00;
          if(f-temp2>0.5) temp2 = temp2+1;
       }
       else temp2 = 1;
       wg =0;
       task = init_task; 
       while(1)
       {
           i = task->netflag;
           k = task->time;
           j = atoi(task->memsze);
           if(j>99) j=99;
           if(k>59) k=59;
           M4.T4[j][k].CN4[i].task5 = (struct task_struct_slc*)malloc(sizeof(struct task_struct_slc));
           M4.T4[j][k].CN4[i].task5->link5 = '\0';
           l = M4.T4[j][k].CN4[i].not5;
           strcpy(M4.T4[j][k].CN4[i].task5->PID5, task->PID);
           strcpy(M4.T4[j][k].CN4[i].task5->memsze5, task->memsze);
           strcpy(M4.T4[j][k].CN4[i].task5->name5, task->name);
       strcpy(M4.T4[j][k].CN4[i].task5->policy5, task->policy);              
       M4.T4[j][k].CN4[i].task5->time5 = task->time;
       M4.T4[j][k].CN4[i].task5->netflag5 = i;      
       l++;
       M4.T4[j][k].CN4[i].not5 = l;
       if(M4.T4[j][k].CN4[i].flag5==0) M4.T4[j][k].CN4[i].init_task5 = M4.T4[j][k].CN4[i].task5;
       if(M4.T4[j][k].CN4[i].flag5>0) M4.T4[j][k].CN4[i].Q5->link5 = M4.T4[j][k].CN4[i].task5;
       M4.T4[j][k].CN4[i].flag5++;
       M4.T4[j][k].CN4[i].Q5 = M4.T4[j][k].CN4[i].task5;
       if(task->link!='\0')
       task = task->link;
       if(wg==1) break;
       if(task->link=='\0') wg=1;
       }    // closing task loop
    a=-20;
    b=-20;  
    v=0;  // for real time processes 
    n=0; // for normal processes
    if(opt=='1')    // internet is preferred, mem from low to high
    {  // 1
      f1 = fopen("output1_slc.txt","w");
     fprintf(f1, "\n1 - Light + small + internet tasks\n2 - Light + small + normal tasks\n3 - Heavy + small + internet tasks\n4 - Heavy + small + normal tasks\n5 - Light + large + internet tasks\n6 - Light + large + normal tasks\n7 - Heavy + large + internet tasks\n8 - Heavy + large + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].init_task5;
          if(M4.T4[j][h].CN4[1].not5>0) 
          { //3
           for(l=0;l<=M4.T4[j][h].CN4[1].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[1].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[1].task5->PID5, M4.T4[j][h].CN4[1].task5->netflag5, M4.T4[j][h].CN4[1].task5->memsze5, M4.T4[j][h].CN4[1].task5->time5, prio, M4.T4[j][h].CN4[1].task5->policy5, M4.T4[j][h].CN4[1].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[1].task5->link5!='\0')
  M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].init_task5;
          if(M4.T4[j][h].CN4[0].not5>0) 
          { //3
             for(l=0;l<=M4.T4[j][h].CN4[0].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[0].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[0].task5->PID5, M4.T4[j][h].CN4[0].task5->netflag5, M4.T4[j][h].CN4[0].task5->memsze5, M4.T4[j][h].CN4[0].task5->time5, prio, M4.T4[j][h].CN4[0].task5->policy5, M4.T4[j][h].CN4[0].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[0].task5->link5!='\0')
  M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_slc'\n\n", opt);
    } // cl 1
    else if(opt=='2')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output2_slc.txt","w");
     fprintf(f1, "\n1 - Light + small + internet tasks\n2 - Light + small + normal tasks\n3 - Heavy + small + internet tasks\n4 - Heavy + small + normal tasks\n5 - Light + large + internet tasks\n6 - Light + large + normal tasks\n7 - Heavy + large + internet tasks\n8 - Heavy + large + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].init_task5;
          if(M4.T4[j][h].CN4[0].not5>0) 
          { //3
             for(l=0;l<=M4.T4[j][h].CN4[0].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[0].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[0].task5->PID5, M4.T4[j][h].CN4[0].task5->netflag5, M4.T4[j][h].CN4[0].task5->memsze5, M4.T4[j][h].CN4[0].task5->time5, prio, M4.T4[j][h].CN4[0].task5->policy5, M4.T4[j][h].CN4[0].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[0].task5->link5!='\0')
  M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].init_task5;
          if(M4.T4[j][h].CN4[1].not5>0) 
          { //3
           for(l=0;l<=M4.T4[j][h].CN4[1].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[1].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[1].task5->PID5, M4.T4[j][h].CN4[1].task5->netflag5, M4.T4[j][h].CN4[1].task5->memsze5, M4.T4[j][h].CN4[1].task5->time5, prio, M4.T4[j][h].CN4[1].task5->policy5, M4.T4[j][h].CN4[1].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[1].task5->link5!='\0')
  M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_slc'\n\n", opt);
    } // cl 1
    else if(opt=='3')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output3_slc.txt","w");
     fprintf(f1, "\n1 - Light + small + internet tasks\n2 - Light + small + normal tasks\n3 - Heavy + small + internet tasks\n4 - Heavy + small + normal tasks\n5 - Light + large + internet tasks\n6 - Light + large + normal tasks\n7 - Heavy + large + internet tasks\n8 - Heavy + large + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].init_task5;
          if(M4.T4[j][h].CN4[1].not5>0) 
          { //3
           for(l=0;l<=M4.T4[j][h].CN4[1].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[1].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[1].task5->PID5, M4.T4[j][h].CN4[1].task5->netflag5, M4.T4[j][h].CN4[1].task5->memsze5, M4.T4[j][h].CN4[1].task5->time5, prio, M4.T4[j][h].CN4[1].task5->policy5, M4.T4[j][h].CN4[1].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[1].task5->link5!='\0')
  M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].init_task5;
          if(M4.T4[j][h].CN4[0].not5>0) 
          { //3
             for(l=0;l<=M4.T4[j][h].CN4[0].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[0].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[0].task5->PID5, M4.T4[j][h].CN4[0].task5->netflag5, M4.T4[j][h].CN4[0].task5->memsze5, M4.T4[j][h].CN4[0].task5->time5, prio, M4.T4[j][h].CN4[0].task5->policy5, M4.T4[j][h].CN4[0].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[0].task5->link5!='\0')
  M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_slc'\n\n", opt);
    } // cl 1
    else if(opt=='4') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output4_slc.txt","w");
     fprintf(f1, "\n1 - Light + small + internet tasks\n2 - Light + small + normal tasks\n3 - Heavy + small + internet tasks\n4 - Heavy + small + normal tasks\n5 - Light + large + internet tasks\n6 - Light + large + normal tasks\n7 - Heavy + large + internet tasks\n8 - Heavy + large + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].init_task5;
          if(M4.T4[j][h].CN4[0].not5>0) 
          { //3
             for(l=0;l<=M4.T4[j][h].CN4[0].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[0].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[0].task5->PID5, M4.T4[j][h].CN4[0].task5->netflag5, M4.T4[j][h].CN4[0].task5->memsze5, M4.T4[j][h].CN4[0].task5->time5, prio, M4.T4[j][h].CN4[0].task5->policy5, M4.T4[j][h].CN4[0].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[0].task5->link5!='\0')
  M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].init_task5;
          if(M4.T4[j][h].CN4[1].not5>0) 
          { //3
           for(l=0;l<=M4.T4[j][h].CN4[1].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[1].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[1].task5->PID5, M4.T4[j][h].CN4[1].task5->netflag5, M4.T4[j][h].CN4[1].task5->memsze5, M4.T4[j][h].CN4[1].task5->time5, prio, M4.T4[j][h].CN4[1].task5->policy5, M4.T4[j][h].CN4[1].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[1].task5->link5!='\0')
  M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_slc'\n\n", opt);
    } // cl 1
else if(opt=='5')   
    {  // 1
      f1 = fopen("output5_slc.txt","w");
     fprintf(f1, "\n1 - Light + small + internet tasks\n2 - Light + small + normal tasks\n3 - Heavy + small + internet tasks\n4 - Heavy + small + normal tasks\n5 - Light + large + internet tasks\n6 - Light + large + normal tasks\n7 - Heavy + large + internet tasks\n8 - Heavy + large + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].init_task5;
          if(M4.T4[j][h].CN4[1].not5>0) 
          { //3
           for(l=0;l<=M4.T4[j][h].CN4[1].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[1].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[1].task5->PID5, M4.T4[j][h].CN4[1].task5->netflag5, M4.T4[j][h].CN4[1].task5->memsze5, M4.T4[j][h].CN4[1].task5->time5, prio, M4.T4[j][h].CN4[1].task5->policy5, M4.T4[j][h].CN4[1].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[1].task5->link5!='\0')
  M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].init_task5;
          if(M4.T4[j][h].CN4[0].not5>0) 
          { //3
             for(l=0;l<=M4.T4[j][h].CN4[0].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[0].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[0].task5->PID5, M4.T4[j][h].CN4[0].task5->netflag5, M4.T4[j][h].CN4[0].task5->memsze5, M4.T4[j][h].CN4[0].task5->time5, prio, M4.T4[j][h].CN4[0].task5->policy5, M4.T4[j][h].CN4[0].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[0].task5->link5!='\0')
  M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_slc'\n\n", opt);
    } // cl 1
    else if(opt=='6')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output6_slc.txt","w");
     fprintf(f1, "\n1 - Light + small + internet tasks\n2 - Light + small + normal tasks\n3 - Heavy + small + internet tasks\n4 - Heavy + small + normal tasks\n5 - Light + large + internet tasks\n6 - Light + large + normal tasks\n7 - Heavy + large + internet tasks\n8 - Heavy + large + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].init_task5;
          if(M4.T4[j][h].CN4[0].not5>0) 
          { //3
             for(l=0;l<=M4.T4[j][h].CN4[0].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[0].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[0].task5->PID5, M4.T4[j][h].CN4[0].task5->netflag5, M4.T4[j][h].CN4[0].task5->memsze5, M4.T4[j][h].CN4[0].task5->time5, prio, M4.T4[j][h].CN4[0].task5->policy5, M4.T4[j][h].CN4[0].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[0].task5->link5!='\0')
  M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].init_task5;
          if(M4.T4[j][h].CN4[1].not5>0) 
          { //3
           for(l=0;l<=M4.T4[j][h].CN4[1].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[1].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[1].task5->PID5, M4.T4[j][h].CN4[1].task5->netflag5, M4.T4[j][h].CN4[1].task5->memsze5, M4.T4[j][h].CN4[1].task5->time5, prio, M4.T4[j][h].CN4[1].task5->policy5, M4.T4[j][h].CN4[1].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[1].task5->link5!='\0')
  M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_slc'\n\n", opt);
    } // cl 1
    else if(opt=='7')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output7_slc.txt","w");
     fprintf(f1, "\n1 - Light + small + internet tasks\n2 - Light + small + normal tasks\n3 - Heavy + small + internet tasks\n4 - Heavy + small + normal tasks\n5 - Light + large + internet tasks\n6 - Light + large + normal tasks\n7 - Heavy + large + internet tasks\n8 - Heavy + large + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].init_task5;
          if(M4.T4[j][h].CN4[1].not5>0) 
          { //3
           for(l=0;l<=M4.T4[j][h].CN4[1].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[1].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[1].task5->PID5, M4.T4[j][h].CN4[1].task5->netflag5, M4.T4[j][h].CN4[1].task5->memsze5, M4.T4[j][h].CN4[1].task5->time5, prio, M4.T4[j][h].CN4[1].task5->policy5, M4.T4[j][h].CN4[1].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[1].task5->link5!='\0')
  M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].init_task5;
          if(M4.T4[j][h].CN4[0].not5>0) 
          { //3
             for(l=0;l<=M4.T4[j][h].CN4[0].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[0].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[0].task5->PID5, M4.T4[j][h].CN4[0].task5->netflag5, M4.T4[j][h].CN4[0].task5->memsze5, M4.T4[j][h].CN4[0].task5->time5, prio, M4.T4[j][h].CN4[0].task5->policy5, M4.T4[j][h].CN4[0].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[0].task5->link5!='\0')
  M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_slc'\n\n", opt);
    } // cl 1
    else if(opt=='8') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output8_slc.txt","w");
     fprintf(f1, "\n1 - Light + small + internet tasks\n2 - Light + small + normal tasks\n3 - Heavy + small + internet tasks\n4 - Heavy + small + normal tasks\n5 - Light + large + internet tasks\n6 - Light + large + normal tasks\n7 - Heavy + large + internet tasks\n8 - Heavy + large + normal tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].init_task5;
          if(M4.T4[j][h].CN4[0].not5>0) 
          { //3
             for(l=0;l<=M4.T4[j][h].CN4[0].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[0].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[0].task5->PID5, M4.T4[j][h].CN4[0].task5->netflag5, M4.T4[j][h].CN4[0].task5->memsze5, M4.T4[j][h].CN4[0].task5->time5, prio, M4.T4[j][h].CN4[0].task5->policy5, M4.T4[j][h].CN4[0].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[0].task5->link5!='\0')
  M4.T4[j][h].CN4[0].task5 = M4.T4[j][h].CN4[0].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].init_task5;
          if(M4.T4[j][h].CN4[1].not5>0) 
          { //3
           for(l=0;l<=M4.T4[j][h].CN4[1].not5-1;l++)
          { // 4
          w = atol(M4.T4[j][h].CN4[1].task5->PID5);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M4.T4[j][h].CN4[1].task5->PID5, M4.T4[j][h].CN4[1].task5->netflag5, M4.T4[j][h].CN4[1].task5->memsze5, M4.T4[j][h].CN4[1].task5->time5, prio, M4.T4[j][h].CN4[1].task5->policy5, M4.T4[j][h].CN4[1].task5->name5); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M4.T4[j][h].CN4[1].task5->link5!='\0')
  M4.T4[j][h].CN4[1].task5 = M4.T4[j][h].CN4[1].task5->link5;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_slc'\n\n", opt);
}    
else printf("\n\n INVALID ENTRY!!!\n\n");
return (1);
} // function is closed
int scl()
{
    char i;
    FILE *F;    
    F = fopen("input2.txt","r");
    fscanf(F, "%c", &i);
    ufs_scl(i);
    return (1);
}
int ufs_scl(char opt)
    {  //  opt option for deciding purpose // lgfle stored logfile          
struct task_struct_scl
{   
    char PID6[15];
    char memsze6[10];
    char name6[50];
    char policy6[15];
    int time6;  // burst time in mins
    int netflag6;
    struct task_struct_scl *link6;
};
struct time_scl
    {
            struct task_struct_scl *task6, *init_task6, *Q6;
            int not6, flag6;
    };
struct conn_scl
    {
            struct time_scl T5[60];
    };
struct mem_scl
       {
            struct conn_scl CN5[100][2];
       };
struct mem_scl M5;
int i, k, len, len1, j, l, temp1, prio, n, a, m, b, temp2, wg, h, non, pol1, pol2, v, g, not9=0;
long int w;
       float q, f;
       char C[15];       // non = number of nodes(mult. of 100 and 40)
       FILE *f1;
           // lgfle has output of “sudo netstat –p”
        
       i = ((maxmem+1)*(maxtme+1)); 
       if(i<6000) non = 2*i;
       else non = 12000;   // wg is for net weight
       pol1 = SCHED_FIFO;  // wg1 for mem weight, wg2 for normal task weight
       pol2 = SCHED_RR;
       for(i=0;i<=maxmem;i++)
       {
           for(j=0;j<=maxtme;j++)
           {
             M5.CN5[i][0].T5[j].not6 = 0;
             M5.CN5[i][1].T5[j].not6 = 0;
             M5.CN5[i][0].T5[j].flag6 = 0;
             M5.CN5[i][1].T5[j].flag6 = 0;
           }
       }
       len=0;
       l=0;
       if(non>=40) 
       {
          temp1 = non/40;
          f = non/40.00;
          if(f-temp1>0.5) temp1 = temp1+1;
       }
       else temp1 = 1;
       if(non>=10) 
       {
          temp2 = non/10;
          f = non/10.00;
          if(f-temp2>0.5) temp2 = temp2+1;
       }
       else temp2 = 1;
       wg =0;
       task = init_task; 
       while(1)
       {
           i = task->netflag;
           k = task->time;
           j = atoi(task->memsze);
           if(j>99) j=99;
           if(k>59) k=59;
           M5.CN5[j][i].T5[k].task6 = (struct task_struct_scl*)malloc(sizeof(struct task_struct_scl));
           M5.CN5[j][i].T5[k].task6->link6 = '\0';
           l = M5.CN5[j][i].T5[k].not6;
           strcpy(M5.CN5[j][i].T5[k].task6->PID6, task->PID);
           strcpy(M5.CN5[j][i].T5[k].task6->memsze6, task->memsze);
           strcpy(M5.CN5[j][i].T5[k].task6->name6, task->name);
       strcpy(M5.CN5[j][i].T5[k].task6->policy6, task->policy);              
       M5.CN5[j][i].T5[k].task6->time6 = task->time;
       M5.CN5[j][i].T5[k].task6->netflag6 = i;      
       l++;
       M5.CN5[j][i].T5[k].not6 = l;
       if(M5.CN5[j][i].T5[k].flag6==0) M5.CN5[j][i].T5[k].init_task6 = M5.CN5[j][i].T5[k].task6;
       if(M5.CN5[j][i].T5[k].flag6>0) M5.CN5[j][i].T5[k].Q6->link6 = M5.CN5[j][i].T5[k].task6;
       M5.CN5[j][i].T5[k].flag6++;
       M5.CN5[j][i].T5[k].Q6 = M5.CN5[j][i].T5[k].task6;
       if(task->link!='\0')
       task = task->link;
       if(wg==1) break;
       if(task->link=='\0') wg=1;
       }    // closing task loop
    a=-20;
    b=-20;  
    v=0;  // for real time processes 
    n=0; // for normal processes
    if(opt=='1')    // internet is preferred, mem from low to high
    {  // 1
      f1 = fopen("output1_scl.txt","w");
     fprintf(f1, "\n1 - Light + internet + small tasks\n2 - Light + normal + small tasks\n3 - Heavy + internet + small tasks\n4 - Heavy + normal + small tasks\n5 - Light + internet + large tasks\n6 - Light + normal + large tasks\n7 - Heavy + internet + large tasks\n8 - Heavy + normal + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].init_task6;
          if(M5.CN5[j][1].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][1].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][1].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][1].T5[h].task6->PID6, M5.CN5[j][1].T5[h].task6->netflag6, M5.CN5[j][1].T5[h].task6->memsze6, M5.CN5[j][1].T5[h].task6->time6, prio, M5.CN5[j][1].T5[h].task6->policy6, M5.CN5[j][1].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][1].T5[h].task6->link6!='\0')
  M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].init_task6;
          if(M5.CN5[j][0].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][0].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][0].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][0].T5[h].task6->PID6, M5.CN5[j][0].T5[h].task6->netflag6, M5.CN5[j][0].T5[h].task6->memsze6, M5.CN5[j][0].T5[h].task6->time6, prio, M5.CN5[j][0].T5[h].task6->policy6, M5.CN5[j][0].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][0].T5[h].task6->link6!='\0')
  M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_scl'\n\n", opt);
    } // cl 1
    else if(opt=='2')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output2_scl.txt","w");
     fprintf(f1, "\n1 - Light + internet + small tasks\n2 - Light + normal + small tasks\n3 - Heavy + internet + small tasks\n4 - Heavy + normal + small tasks\n5 - Light + internet + large tasks\n6 - Light + normal + large tasks\n7 - Heavy + internet + large tasks\n8 - Heavy + normal + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].init_task6;
          if(M5.CN5[j][0].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][0].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][0].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][0].T5[h].task6->PID6, M5.CN5[j][0].T5[h].task6->netflag6, M5.CN5[j][0].T5[h].task6->memsze6, M5.CN5[j][0].T5[h].task6->time6, prio, M5.CN5[j][0].T5[h].task6->policy6, M5.CN5[j][0].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][0].T5[h].task6->link6!='\0')
  M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].init_task6;
          if(M5.CN5[j][1].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][1].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][1].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][1].T5[h].task6->PID6, M5.CN5[j][1].T5[h].task6->netflag6, M5.CN5[j][1].T5[h].task6->memsze6, M5.CN5[j][1].T5[h].task6->time6, prio, M5.CN5[j][1].T5[h].task6->policy6, M5.CN5[j][1].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][1].T5[h].task6->link6!='\0')
  M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_scl'\n\n", opt);
    } // cl 1
    else if(opt=='3')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output3_scl.txt","w");
     fprintf(f1, "\n1 - Light + internet + small tasks\n2 - Light + normal + small tasks\n3 - Heavy + internet + small tasks\n4 - Heavy + normal + small tasks\n5 - Light + internet + large tasks\n6 - Light + normal + large tasks\n7 - Heavy + internet + large tasks\n8 - Heavy + normal + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].init_task6;
          if(M5.CN5[j][1].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][1].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][1].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][1].T5[h].task6->PID6, M5.CN5[j][1].T5[h].task6->netflag6, M5.CN5[j][1].T5[h].task6->memsze6, M5.CN5[j][1].T5[h].task6->time6, prio, M5.CN5[j][1].T5[h].task6->policy6, M5.CN5[j][1].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][1].T5[h].task6->link6!='\0')
  M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].init_task6;
          if(M5.CN5[j][0].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][0].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][0].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][0].T5[h].task6->PID6, M5.CN5[j][0].T5[h].task6->netflag6, M5.CN5[j][0].T5[h].task6->memsze6, M5.CN5[j][0].T5[h].task6->time6, prio, M5.CN5[j][0].T5[h].task6->policy6, M5.CN5[j][0].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][0].T5[h].task6->link6!='\0')
  M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_scl'\n\n", opt);
    } // cl 1
    else if(opt=='4') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output4_scl.txt","w");
     fprintf(f1, "\n1 - Light + internet + small tasks\n2 - Light + normal + small tasks\n3 - Heavy + internet + small tasks\n4 - Heavy + normal + small tasks\n5 - Light + internet + large tasks\n6 - Light + normal + large tasks\n7 - Heavy + internet + large tasks\n8 - Heavy + normal + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].init_task6;
          if(M5.CN5[j][0].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][0].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][0].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][0].T5[h].task6->PID6, M5.CN5[j][0].T5[h].task6->netflag6, M5.CN5[j][0].T5[h].task6->memsze6, M5.CN5[j][0].T5[h].task6->time6, prio, M5.CN5[j][0].T5[h].task6->policy6, M5.CN5[j][0].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][0].T5[h].task6->link6!='\0')
  M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=0;h<=maxtme;h++)
          {  // 2
          M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].init_task6;
          if(M5.CN5[j][1].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][1].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][1].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][1].T5[h].task6->PID6, M5.CN5[j][1].T5[h].task6->netflag6, M5.CN5[j][1].T5[h].task6->memsze6, M5.CN5[j][1].T5[h].task6->time6, prio, M5.CN5[j][1].T5[h].task6->policy6, M5.CN5[j][1].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][1].T5[h].task6->link6!='\0')
  M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_scl'\n\n", opt);
    } // cl 1
else if(opt=='5')   
    {  // 1
      f1 = fopen("output5_scl.txt","w");
     fprintf(f1, "\n1 - Light + internet + small tasks\n2 - Light + normal + small tasks\n3 - Heavy + internet + small tasks\n4 - Heavy + normal + small tasks\n5 - Light + internet + large tasks\n6 - Light + normal + large tasks\n7 - Heavy + internet + large tasks\n8 - Heavy + normal + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].init_task6;
          if(M5.CN5[j][1].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][1].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][1].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][1].T5[h].task6->PID6, M5.CN5[j][1].T5[h].task6->netflag6, M5.CN5[j][1].T5[h].task6->memsze6, M5.CN5[j][1].T5[h].task6->time6, prio, M5.CN5[j][1].T5[h].task6->policy6, M5.CN5[j][1].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][1].T5[h].task6->link6!='\0')
  M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].init_task6;
          if(M5.CN5[j][0].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][0].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][0].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][0].T5[h].task6->PID6, M5.CN5[j][0].T5[h].task6->netflag6, M5.CN5[j][0].T5[h].task6->memsze6, M5.CN5[j][0].T5[h].task6->time6, prio, M5.CN5[j][0].T5[h].task6->policy6, M5.CN5[j][0].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][0].T5[h].task6->link6!='\0')
  M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_scl'\n\n", opt);
    } // cl 1
    else if(opt=='6')   // internet is not preferred, mem from low to high
    { 
      f1 = fopen("output6_scl.txt","w");
     fprintf(f1, "\n1 - Light + internet + small tasks\n2 - Light + normal + small tasks\n3 - Heavy + internet + small tasks\n4 - Heavy + normal + small tasks\n5 - Light + internet + large tasks\n6 - Light + normal + large tasks\n7 - Heavy + internet + large tasks\n8 - Heavy + normal + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].init_task6;
          if(M5.CN5[j][0].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][0].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][0].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][0].T5[h].task6->PID6, M5.CN5[j][0].T5[h].task6->netflag6, M5.CN5[j][0].T5[h].task6->memsze6, M5.CN5[j][0].T5[h].task6->time6, prio, M5.CN5[j][0].T5[h].task6->policy6, M5.CN5[j][0].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][0].T5[h].task6->link6!='\0')
  M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=0;j<=maxmem;j++)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].init_task6;
          if(M5.CN5[j][1].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][1].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][1].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][1].T5[h].task6->PID6, M5.CN5[j][1].T5[h].task6->netflag6, M5.CN5[j][1].T5[h].task6->memsze6, M5.CN5[j][1].T5[h].task6->time6, prio, M5.CN5[j][1].T5[h].task6->policy6, M5.CN5[j][1].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][1].T5[h].task6->link6!='\0')
  M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_scl'\n\n", opt);
    } // cl 1
    else if(opt=='7')    // internet is preferred, mem from high to low
    { 
      f1 = fopen("output7_scl.txt","w");
     fprintf(f1, "\n1 - Light + internet + small tasks\n2 - Light + normal + small tasks\n3 - Heavy + internet + small tasks\n4 - Heavy + normal + small tasks\n5 - Light + internet + large tasks\n6 - Light + normal + large tasks\n7 - Heavy + internet + large tasks\n8 - Heavy + normal + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].init_task6;
          if(M5.CN5[j][1].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][1].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][1].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][1].T5[h].task6->PID6, M5.CN5[j][1].T5[h].task6->netflag6, M5.CN5[j][1].T5[h].task6->memsze6, M5.CN5[j][1].T5[h].task6->time6, prio, M5.CN5[j][1].T5[h].task6->policy6, M5.CN5[j][1].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][1].T5[h].task6->link6!='\0')
  M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].init_task6;
          if(M5.CN5[j][0].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][0].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][0].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][0].T5[h].task6->PID6, M5.CN5[j][0].T5[h].task6->netflag6, M5.CN5[j][0].T5[h].task6->memsze6, M5.CN5[j][0].T5[h].task6->time6, prio, M5.CN5[j][0].T5[h].task6->policy6, M5.CN5[j][0].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][0].T5[h].task6->link6!='\0')
  M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_scl'\n\n", opt);
    } // cl 1
    else if(opt=='8') // internet is not preferred, mem from high to low
    {
      f1 = fopen("output8_scl.txt","w");
     fprintf(f1, "\n1 - Light + internet + small tasks\n2 - Light + normal + small tasks\n3 - Heavy + internet + small tasks\n4 - Heavy + normal + small tasks\n5 - Light + internet + large tasks\n6 - Light + normal + large tasks\n7 - Heavy + internet + large tasks\n8 - Heavy + normal + large tasks\n\nc - connectivity of tasks\nl - length of tasks\ns - size of tasks\n\nNumber of tasks owned by current users and the root is %d\n\nPID---connected---memory---time---priority---policy---name\n\n", not);
         for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].init_task6;
          if(M5.CN5[j][0].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][0].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][0].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][0].T5[h].task6->PID6, M5.CN5[j][0].T5[h].task6->netflag6, M5.CN5[j][0].T5[h].task6->memsze6, M5.CN5[j][0].T5[h].task6->time6, prio, M5.CN5[j][0].T5[h].task6->policy6, M5.CN5[j][0].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][0].T5[h].task6->link6!='\0')
  M5.CN5[j][0].T5[h].task6 = M5.CN5[j][0].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1
        for(j=maxmem;j>=0;j--)
        { // 1
          for(h=maxtme;h>=0;h--)
          {  // 2
          M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].init_task6;
          if(M5.CN5[j][1].T5[h].not6>0) 
          { //3
           for(l=0;l<=M5.CN5[j][1].T5[h].not6-1;l++)
          { // 4
          w = atol(M5.CN5[j][1].T5[h].task6->PID6);
          if((sched_getscheduler(w)!=pol1)&&(sched_getscheduler(w)!=pol2))
           prio = a;
          else 
           prio = b; 
          fprintf(f1, "%s   %d   %s   %d   %d   %s   %s\n", M5.CN5[j][1].T5[h].task6->PID6, M5.CN5[j][1].T5[h].task6->netflag6, M5.CN5[j][1].T5[h].task6->memsze6, M5.CN5[j][1].T5[h].task6->time6, prio, M5.CN5[j][1].T5[h].task6->policy6, M5.CN5[j][1].T5[h].task6->name6); not9++;
          setpriority(PRIO_PROCESS, w, prio);
if(M5.CN5[j][1].T5[h].task6->link6!='\0')
  M5.CN5[j][1].T5[h].task6 = M5.CN5[j][1].T5[h].task6->link6;
          } // cl 4
          }// cl 3
        n++;
        v++;
        if(n==temp1)
        {
           if(a<20)
             a++;
            n=0;
        }
        if(v==temp2)
        {
           if(b<-10)
              b++;
           v=0;
        }
        } } // cl 2, 1    
    fclose(f1);
    printf("\n\nDONE...CHECK OUT THE RESULT IN 'output%c_scl'\n\n", opt);
}    
else printf("\n\n INVALID ENTRY!!!\n\n");
return (1);
} // function is closed
