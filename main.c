#include "stdio.h" 
#include "string.h" 
 
#define CMD_NUM 3
#define CMD_LEN 2
 
typedef int (* FUNC)(int);
void *cmd_tables[CMD_NUM][CMD_LEN];
 
int cmd_foreach(void *cmd_tables[CMD_NUM][CMD_LEN], char *cmd);
int *get_info_1(int id);
int *get_info_2(int id);
 
char buf[256]={0};
 
int main()
{
    int cmd_vector;
    int id = 1;
    char cmd[20] ={0};
 
    /* ex: receive "get_info_1" */
    sprintf(cmd,"get_info_1");
 
    printf("receive command = %s\n", cmd);
 
    cmd_vector = cmd_foreach(cmd_tables, cmd);
    if(cmd_vector != -1 )
    {
        ((FUNC)cmd_tables[cmd_vector][1])(id);
        memset(buf,0,sizeof(buf));
        memset(cmd,0,sizeof(cmd));
    }
    printf("wait for next command ...\n");
}
 
int cmd_foreach(void *cmd_tables[CMD_NUM][CMD_LEN], char *cmd)
{
    int i = 0;
    int match = 0;
    int cmd_index = -1;
 
    for (i = 0; cmd_tables[i][0]; i++)
    {
        if(!strcmp(cmd_tables[i][0], cmd))
        {
            printf("cmd_tables[%d][0] = %s, cmd = %s\n", i, (char *)cmd_tables[i][0], cmd);
            match++;
            cmd_index = i;
        }
    }
    if (match == 1)
    {
        return cmd_index;
    }
    else
    {
        return -1;
    }
}
int *get_info_1(int id)
{
    printf("get %d info_1\n",id);
    /* do your code here */
    return 0;
}
 
int *get_info_2(int id)
{
    printf("get %d info_2\n",id);
 
    /* do your code here */
 
    return 0;
}
 
void *cmd_tables[CMD_NUM][CMD_LEN]={
    { "get_info_1", get_info_1 },
    { "get_info_2", get_info_2 },
    /* add new function in this array */
    { NULL, NULL }
};
