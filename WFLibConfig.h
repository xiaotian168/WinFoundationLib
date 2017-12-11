
#pragma once

#define WF_STATIC_BUILD
#define WF_DYNAMIC_BUILD

#if defined WF_STATIC_BUILD
#	define WF_API
#	define WF_CAPI extern "C"
#else
#	if defined _WF_API
#		define WF_API __declspec(dllexport)
#		define WF_CAPI extern "C" __declspec(dllexport)
#	else
#		define WF_API __declspec(dllimport)
#		define WF_CAPI extern "C" __declspec(dllimport)
#	endif
#endif
