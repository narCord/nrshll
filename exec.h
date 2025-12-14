int determine_command_type(const char *cmd);
int execute_external(char **cmd_and_args);
int execute_internal(char **cmd_and_args);
void exec_cd(char **cmd_and_args);
void exec_exit();
//exec_help();
