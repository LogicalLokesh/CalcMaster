//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#pragma once

#define CALC_VERSION "1.0.3"

// operation_return_reason stores the reasons when functions terminate.
enum operation_return_reason
{
	return_reason_success,
	return_reason_failure,
	return_reason_error,
	return_reason_user_exit
};
