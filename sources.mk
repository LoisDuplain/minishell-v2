SOURCES += sources/builtin/cd_builtin.c
SOURCES += sources/builtin/echo_builtin.c
SOURCES += sources/builtin/env_builtin.c
SOURCES += sources/builtin/exit_builtin.c
SOURCES += sources/builtin/export_builtin.c
SOURCES += sources/builtin/get_builtin.c
SOURCES += sources/builtin/pwd_builtin.c
SOURCES += sources/builtin/unset_builtin.c
SOURCES += sources/cmd_builder/create_cmd_builder.c
SOURCES += sources/cmd_builder/destroy_cmd_builder.c
SOURCES += sources/cmd_builder/display_cmd_builder.c
SOURCES += sources/cmd_builder/get_cmds_length.c
SOURCES += sources/cmd_builder/next_cmd.c
SOURCES += sources/cmd_builder/next_cmd_part.c
SOURCES += sources/cmd_builder/parse_line.c
SOURCES += sources/exit_shell.c
SOURCES += sources/main.c
SOURCES += sources/parser/all_quotes_are_closed.c
SOURCES += sources/parser/dispatch_parsing.c
SOURCES += sources/parser/parse.c
SOURCES += sources/parser/parse_pipe.c
SOURCES += sources/parser/parse_quote.c
SOURCES += sources/parser/parse_redirection.c
SOURCES += sources/process/append_env_var_to_str.c
SOURCES += sources/process/execute/build_program_path.c
SOURCES += sources/process/execute/execute_cmd.c
SOURCES += sources/process/execute/execute_program.c
SOURCES += sources/process/execute/get_program_path.c
SOURCES += sources/process/execute/program_exists_at.c
SOURCES += sources/process/get_env_var_name.c
SOURCES += sources/process/get_processed_arg.c
SOURCES += sources/process/get_processed_quote.c
SOURCES += sources/process/process_cmd.c
SOURCES += sources/process/process_cmds.c
SOURCES += sources/process/redirection/dispatch_redirection.c
SOURCES += sources/process/redirection/get_output_redirection_mode.c
SOURCES += sources/process/redirection/is_redirection.c
SOURCES += sources/process/redirection/read_until_keyword.c
SOURCES += sources/process/redirection/start_file_redirection.c
SOURCES += sources/process/redirection/start_shell_redirection.c
SOURCES += sources/process/redirection/stop_shell_redirection.c
SOURCES += sources/put_error.c
SOURCES += sources/shell/create_shell.c
SOURCES += sources/shell/destroy_shell.c
SOURCES += sources/shell/environment/create_env.c
SOURCES += sources/shell/environment/get_env_length.c
SOURCES += sources/shell/environment/get_env_var.c
SOURCES += sources/shell/environment/get_env_var_index.c
SOURCES += sources/shell/environment/set_env_var.c
SOURCES += sources/shell/environment/unset_env_var.c
SOURCES += sources/shell/set_line.c
SOURCES += sources/shell/update_prompt.c
SOURCES += sources/signal/ctrl_backslash_signal.c
SOURCES += sources/signal/ctrl_c_signal.c
