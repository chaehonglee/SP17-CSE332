// common.h
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : common usage msg header file

#pragma once
#ifndef COMMON_HEADER
#define COMMON_HEADER
#include <string>
using namespace std;

enum array_index
{
	prog_name,
	input_name,
	board_size = 2,
	start_piece = 3,
	arg_size_default = 2,
	arg_size_ms_boardsize = 3,
	arg_size_ms_startpeice = 4,
	length_input_string = 3
};
enum result_codes 
{
	success, 
	enum_cmd_args, 
	unknown_error, 
	enum_done, 
	enum_quit, 
	enum_stalemate, 
	enum_few_args, 
	enum_wrong_arg, 
	enum_more_args,
	valid_piece
};
int usage(string prog_name, result_codes error);
#endif
