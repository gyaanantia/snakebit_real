/*lint -e???? -save */
/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_nrf_raal_api.h"

typedef struct _CMOCK_nrf_raal_init_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_nrf_raal_init_CALL_INSTANCE;

typedef struct _CMOCK_nrf_raal_uninit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_nrf_raal_uninit_CALL_INSTANCE;

typedef struct _CMOCK_nrf_raal_continuous_mode_enter_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_nrf_raal_continuous_mode_enter_CALL_INSTANCE;

typedef struct _CMOCK_nrf_raal_continuous_mode_exit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_nrf_raal_continuous_mode_exit_CALL_INSTANCE;

typedef struct _CMOCK_nrf_raal_continuous_ended_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_nrf_raal_continuous_ended_CALL_INSTANCE;

typedef struct _CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  bool ReturnVal;
  int CallOrder;
  uint32_t Expected_length_us;
  int IgnoreArg_length_us;

} CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE;

typedef struct _CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint32_t ReturnVal;
  int CallOrder;

} CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE;

typedef struct _CMOCK_nrf_raal_critical_section_enter_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_nrf_raal_critical_section_enter_CALL_INSTANCE;

typedef struct _CMOCK_nrf_raal_critical_section_exit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_nrf_raal_critical_section_exit_CALL_INSTANCE;

static struct mock_nrf_raal_apiInstance
{
  int nrf_raal_init_IgnoreBool;
  CMOCK_nrf_raal_init_CALLBACK nrf_raal_init_CallbackFunctionPointer;
  int nrf_raal_init_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nrf_raal_init_CallInstance;
  int nrf_raal_uninit_IgnoreBool;
  CMOCK_nrf_raal_uninit_CALLBACK nrf_raal_uninit_CallbackFunctionPointer;
  int nrf_raal_uninit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nrf_raal_uninit_CallInstance;
  int nrf_raal_continuous_mode_enter_IgnoreBool;
  CMOCK_nrf_raal_continuous_mode_enter_CALLBACK nrf_raal_continuous_mode_enter_CallbackFunctionPointer;
  int nrf_raal_continuous_mode_enter_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nrf_raal_continuous_mode_enter_CallInstance;
  int nrf_raal_continuous_mode_exit_IgnoreBool;
  CMOCK_nrf_raal_continuous_mode_exit_CALLBACK nrf_raal_continuous_mode_exit_CallbackFunctionPointer;
  int nrf_raal_continuous_mode_exit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nrf_raal_continuous_mode_exit_CallInstance;
  int nrf_raal_continuous_ended_IgnoreBool;
  CMOCK_nrf_raal_continuous_ended_CALLBACK nrf_raal_continuous_ended_CallbackFunctionPointer;
  int nrf_raal_continuous_ended_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nrf_raal_continuous_ended_CallInstance;
  int nrf_raal_timeslot_request_IgnoreBool;
  bool nrf_raal_timeslot_request_FinalReturn;
  CMOCK_nrf_raal_timeslot_request_CALLBACK nrf_raal_timeslot_request_CallbackFunctionPointer;
  int nrf_raal_timeslot_request_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nrf_raal_timeslot_request_CallInstance;
  int nrf_raal_timeslot_us_left_get_IgnoreBool;
  uint32_t nrf_raal_timeslot_us_left_get_FinalReturn;
  CMOCK_nrf_raal_timeslot_us_left_get_CALLBACK nrf_raal_timeslot_us_left_get_CallbackFunctionPointer;
  int nrf_raal_timeslot_us_left_get_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nrf_raal_timeslot_us_left_get_CallInstance;
  int nrf_raal_critical_section_enter_IgnoreBool;
  CMOCK_nrf_raal_critical_section_enter_CALLBACK nrf_raal_critical_section_enter_CallbackFunctionPointer;
  int nrf_raal_critical_section_enter_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nrf_raal_critical_section_enter_CallInstance;
  int nrf_raal_critical_section_exit_IgnoreBool;
  CMOCK_nrf_raal_critical_section_exit_CALLBACK nrf_raal_critical_section_exit_CallbackFunctionPointer;
  int nrf_raal_critical_section_exit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nrf_raal_critical_section_exit_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_nrf_raal_api_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.nrf_raal_init_CallInstance, cmock_line, "Function 'nrf_raal_init' called less times than expected.");
  if (Mock.nrf_raal_init_CallbackFunctionPointer != NULL)
    Mock.nrf_raal_init_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.nrf_raal_uninit_CallInstance, cmock_line, "Function 'nrf_raal_uninit' called less times than expected.");
  if (Mock.nrf_raal_uninit_CallbackFunctionPointer != NULL)
    Mock.nrf_raal_uninit_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.nrf_raal_continuous_mode_enter_CallInstance, cmock_line, "Function 'nrf_raal_continuous_mode_enter' called less times than expected.");
  if (Mock.nrf_raal_continuous_mode_enter_CallbackFunctionPointer != NULL)
    Mock.nrf_raal_continuous_mode_enter_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.nrf_raal_continuous_mode_exit_CallInstance, cmock_line, "Function 'nrf_raal_continuous_mode_exit' called less times than expected.");
  if (Mock.nrf_raal_continuous_mode_exit_CallbackFunctionPointer != NULL)
    Mock.nrf_raal_continuous_mode_exit_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.nrf_raal_continuous_ended_CallInstance, cmock_line, "Function 'nrf_raal_continuous_ended' called less times than expected.");
  if (Mock.nrf_raal_continuous_ended_CallbackFunctionPointer != NULL)
    Mock.nrf_raal_continuous_ended_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.nrf_raal_timeslot_request_CallInstance, cmock_line, "Function 'nrf_raal_timeslot_request' called less times than expected.");
  if (Mock.nrf_raal_timeslot_request_CallbackFunctionPointer != NULL)
    Mock.nrf_raal_timeslot_request_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.nrf_raal_timeslot_us_left_get_CallInstance, cmock_line, "Function 'nrf_raal_timeslot_us_left_get' called less times than expected.");
  if (Mock.nrf_raal_timeslot_us_left_get_CallbackFunctionPointer != NULL)
    Mock.nrf_raal_timeslot_us_left_get_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.nrf_raal_critical_section_enter_CallInstance, cmock_line, "Function 'nrf_raal_critical_section_enter' called less times than expected.");
  if (Mock.nrf_raal_critical_section_enter_CallbackFunctionPointer != NULL)
    Mock.nrf_raal_critical_section_enter_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.nrf_raal_critical_section_exit_CallInstance, cmock_line, "Function 'nrf_raal_critical_section_exit' called less times than expected.");
  if (Mock.nrf_raal_critical_section_exit_CallbackFunctionPointer != NULL)
    Mock.nrf_raal_critical_section_exit_CallInstance = CMOCK_GUTS_NONE;
}

void mock_nrf_raal_api_Init(void)
{
  mock_nrf_raal_api_Destroy();
}

void mock_nrf_raal_api_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.nrf_raal_init_CallbackFunctionPointer = NULL;
  Mock.nrf_raal_init_CallbackCalls = 0;
  Mock.nrf_raal_uninit_CallbackFunctionPointer = NULL;
  Mock.nrf_raal_uninit_CallbackCalls = 0;
  Mock.nrf_raal_continuous_mode_enter_CallbackFunctionPointer = NULL;
  Mock.nrf_raal_continuous_mode_enter_CallbackCalls = 0;
  Mock.nrf_raal_continuous_mode_exit_CallbackFunctionPointer = NULL;
  Mock.nrf_raal_continuous_mode_exit_CallbackCalls = 0;
  Mock.nrf_raal_continuous_ended_CallbackFunctionPointer = NULL;
  Mock.nrf_raal_continuous_ended_CallbackCalls = 0;
  Mock.nrf_raal_timeslot_request_CallbackFunctionPointer = NULL;
  Mock.nrf_raal_timeslot_request_CallbackCalls = 0;
  Mock.nrf_raal_timeslot_us_left_get_CallbackFunctionPointer = NULL;
  Mock.nrf_raal_timeslot_us_left_get_CallbackCalls = 0;
  Mock.nrf_raal_critical_section_enter_CallbackFunctionPointer = NULL;
  Mock.nrf_raal_critical_section_enter_CallbackCalls = 0;
  Mock.nrf_raal_critical_section_exit_CallbackFunctionPointer = NULL;
  Mock.nrf_raal_critical_section_exit_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void nrf_raal_init(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nrf_raal_init_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nrf_raal_init_CallInstance);
  Mock.nrf_raal_init_CallInstance = CMock_Guts_MemNext(Mock.nrf_raal_init_CallInstance);
  if (Mock.nrf_raal_init_IgnoreBool)
  {
    return;
  }
  if (Mock.nrf_raal_init_CallbackFunctionPointer != NULL)
  {
    Mock.nrf_raal_init_CallbackFunctionPointer(Mock.nrf_raal_init_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'nrf_raal_init' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_init' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_init' called later than expected.");
}

void nrf_raal_init_CMockIgnore(void)
{
  Mock.nrf_raal_init_IgnoreBool = (int)1;
}

void nrf_raal_init_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_init_CALL_INSTANCE));
  CMOCK_nrf_raal_init_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_init_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_init_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void nrf_raal_init_StubWithCallback(CMOCK_nrf_raal_init_CALLBACK Callback)
{
  Mock.nrf_raal_init_CallbackFunctionPointer = Callback;
}

void nrf_raal_uninit(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nrf_raal_uninit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_uninit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nrf_raal_uninit_CallInstance);
  Mock.nrf_raal_uninit_CallInstance = CMock_Guts_MemNext(Mock.nrf_raal_uninit_CallInstance);
  if (Mock.nrf_raal_uninit_IgnoreBool)
  {
    return;
  }
  if (Mock.nrf_raal_uninit_CallbackFunctionPointer != NULL)
  {
    Mock.nrf_raal_uninit_CallbackFunctionPointer(Mock.nrf_raal_uninit_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'nrf_raal_uninit' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_uninit' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_uninit' called later than expected.");
}

void nrf_raal_uninit_CMockIgnore(void)
{
  Mock.nrf_raal_uninit_IgnoreBool = (int)1;
}

void nrf_raal_uninit_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_uninit_CALL_INSTANCE));
  CMOCK_nrf_raal_uninit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_uninit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_uninit_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_uninit_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void nrf_raal_uninit_StubWithCallback(CMOCK_nrf_raal_uninit_CALLBACK Callback)
{
  Mock.nrf_raal_uninit_CallbackFunctionPointer = Callback;
}

void nrf_raal_continuous_mode_enter(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nrf_raal_continuous_mode_enter_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_continuous_mode_enter_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nrf_raal_continuous_mode_enter_CallInstance);
  Mock.nrf_raal_continuous_mode_enter_CallInstance = CMock_Guts_MemNext(Mock.nrf_raal_continuous_mode_enter_CallInstance);
  if (Mock.nrf_raal_continuous_mode_enter_IgnoreBool)
  {
    return;
  }
  if (Mock.nrf_raal_continuous_mode_enter_CallbackFunctionPointer != NULL)
  {
    Mock.nrf_raal_continuous_mode_enter_CallbackFunctionPointer(Mock.nrf_raal_continuous_mode_enter_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'nrf_raal_continuous_mode_enter' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_continuous_mode_enter' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_continuous_mode_enter' called later than expected.");
}

void nrf_raal_continuous_mode_enter_CMockIgnore(void)
{
  Mock.nrf_raal_continuous_mode_enter_IgnoreBool = (int)1;
}

void nrf_raal_continuous_mode_enter_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_continuous_mode_enter_CALL_INSTANCE));
  CMOCK_nrf_raal_continuous_mode_enter_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_continuous_mode_enter_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_continuous_mode_enter_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_continuous_mode_enter_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void nrf_raal_continuous_mode_enter_StubWithCallback(CMOCK_nrf_raal_continuous_mode_enter_CALLBACK Callback)
{
  Mock.nrf_raal_continuous_mode_enter_CallbackFunctionPointer = Callback;
}

void nrf_raal_continuous_mode_exit(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nrf_raal_continuous_mode_exit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_continuous_mode_exit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nrf_raal_continuous_mode_exit_CallInstance);
  Mock.nrf_raal_continuous_mode_exit_CallInstance = CMock_Guts_MemNext(Mock.nrf_raal_continuous_mode_exit_CallInstance);
  if (Mock.nrf_raal_continuous_mode_exit_IgnoreBool)
  {
    return;
  }
  if (Mock.nrf_raal_continuous_mode_exit_CallbackFunctionPointer != NULL)
  {
    Mock.nrf_raal_continuous_mode_exit_CallbackFunctionPointer(Mock.nrf_raal_continuous_mode_exit_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'nrf_raal_continuous_mode_exit' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_continuous_mode_exit' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_continuous_mode_exit' called later than expected.");
}

void nrf_raal_continuous_mode_exit_CMockIgnore(void)
{
  Mock.nrf_raal_continuous_mode_exit_IgnoreBool = (int)1;
}

void nrf_raal_continuous_mode_exit_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_continuous_mode_exit_CALL_INSTANCE));
  CMOCK_nrf_raal_continuous_mode_exit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_continuous_mode_exit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_continuous_mode_exit_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_continuous_mode_exit_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void nrf_raal_continuous_mode_exit_StubWithCallback(CMOCK_nrf_raal_continuous_mode_exit_CALLBACK Callback)
{
  Mock.nrf_raal_continuous_mode_exit_CallbackFunctionPointer = Callback;
}

void nrf_raal_continuous_ended(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nrf_raal_continuous_ended_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_continuous_ended_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nrf_raal_continuous_ended_CallInstance);
  Mock.nrf_raal_continuous_ended_CallInstance = CMock_Guts_MemNext(Mock.nrf_raal_continuous_ended_CallInstance);
  if (Mock.nrf_raal_continuous_ended_IgnoreBool)
  {
    return;
  }
  if (Mock.nrf_raal_continuous_ended_CallbackFunctionPointer != NULL)
  {
    Mock.nrf_raal_continuous_ended_CallbackFunctionPointer(Mock.nrf_raal_continuous_ended_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'nrf_raal_continuous_ended' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_continuous_ended' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_continuous_ended' called later than expected.");
}

void nrf_raal_continuous_ended_CMockIgnore(void)
{
  Mock.nrf_raal_continuous_ended_IgnoreBool = (int)1;
}

void nrf_raal_continuous_ended_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_continuous_ended_CALL_INSTANCE));
  CMOCK_nrf_raal_continuous_ended_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_continuous_ended_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_continuous_ended_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_continuous_ended_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void nrf_raal_continuous_ended_StubWithCallback(CMOCK_nrf_raal_continuous_ended_CALLBACK Callback)
{
  Mock.nrf_raal_continuous_ended_CallbackFunctionPointer = Callback;
}

bool nrf_raal_timeslot_request(uint32_t length_us)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nrf_raal_timeslot_request_CallInstance);
  Mock.nrf_raal_timeslot_request_CallInstance = CMock_Guts_MemNext(Mock.nrf_raal_timeslot_request_CallInstance);
  if (Mock.nrf_raal_timeslot_request_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.nrf_raal_timeslot_request_FinalReturn;
    Mock.nrf_raal_timeslot_request_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.nrf_raal_timeslot_request_CallbackFunctionPointer != NULL)
  {
    return Mock.nrf_raal_timeslot_request_CallbackFunctionPointer(length_us, Mock.nrf_raal_timeslot_request_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'nrf_raal_timeslot_request' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_timeslot_request' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_timeslot_request' called later than expected.");
  if (!cmock_call_instance->IgnoreArg_length_us)
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_length_us, length_us, cmock_line, "Function 'nrf_raal_timeslot_request' called with unexpected value for argument 'length_us'.");
  }
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_nrf_raal_timeslot_request(CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE* cmock_call_instance, uint32_t length_us)
{
  cmock_call_instance->Expected_length_us = length_us;
  cmock_call_instance->IgnoreArg_length_us = 0;
}

void nrf_raal_timeslot_request_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE));
  CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_timeslot_request_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_timeslot_request_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.nrf_raal_timeslot_request_IgnoreBool = (int)1;
}

void nrf_raal_timeslot_request_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t length_us, bool cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE));
  CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_timeslot_request_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_timeslot_request_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_nrf_raal_timeslot_request(cmock_call_instance, length_us);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void nrf_raal_timeslot_request_StubWithCallback(CMOCK_nrf_raal_timeslot_request_CALLBACK Callback)
{
  Mock.nrf_raal_timeslot_request_CallbackFunctionPointer = Callback;
}

void nrf_raal_timeslot_request_CMockIgnoreArg_length_us(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE* cmock_call_instance = cmock_call_instance = (CMOCK_nrf_raal_timeslot_request_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.nrf_raal_timeslot_request_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "length_us IgnoreArg called before Expect on 'nrf_raal_timeslot_request'.");
  cmock_call_instance->IgnoreArg_length_us = 1;
}

uint32_t nrf_raal_timeslot_us_left_get(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nrf_raal_timeslot_us_left_get_CallInstance);
  Mock.nrf_raal_timeslot_us_left_get_CallInstance = CMock_Guts_MemNext(Mock.nrf_raal_timeslot_us_left_get_CallInstance);
  if (Mock.nrf_raal_timeslot_us_left_get_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.nrf_raal_timeslot_us_left_get_FinalReturn;
    Mock.nrf_raal_timeslot_us_left_get_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.nrf_raal_timeslot_us_left_get_CallbackFunctionPointer != NULL)
  {
    return Mock.nrf_raal_timeslot_us_left_get_CallbackFunctionPointer(Mock.nrf_raal_timeslot_us_left_get_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'nrf_raal_timeslot_us_left_get' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_timeslot_us_left_get' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_timeslot_us_left_get' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void nrf_raal_timeslot_us_left_get_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE));
  CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_timeslot_us_left_get_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_timeslot_us_left_get_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.nrf_raal_timeslot_us_left_get_IgnoreBool = (int)1;
}

void nrf_raal_timeslot_us_left_get_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE));
  CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_timeslot_us_left_get_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_timeslot_us_left_get_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_timeslot_us_left_get_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void nrf_raal_timeslot_us_left_get_StubWithCallback(CMOCK_nrf_raal_timeslot_us_left_get_CALLBACK Callback)
{
  Mock.nrf_raal_timeslot_us_left_get_CallbackFunctionPointer = Callback;
}

void nrf_raal_critical_section_enter(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nrf_raal_critical_section_enter_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_critical_section_enter_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nrf_raal_critical_section_enter_CallInstance);
  Mock.nrf_raal_critical_section_enter_CallInstance = CMock_Guts_MemNext(Mock.nrf_raal_critical_section_enter_CallInstance);
  if (Mock.nrf_raal_critical_section_enter_IgnoreBool)
  {
    return;
  }
  if (Mock.nrf_raal_critical_section_enter_CallbackFunctionPointer != NULL)
  {
    Mock.nrf_raal_critical_section_enter_CallbackFunctionPointer(Mock.nrf_raal_critical_section_enter_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'nrf_raal_critical_section_enter' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_critical_section_enter' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_critical_section_enter' called later than expected.");
}

void nrf_raal_critical_section_enter_CMockIgnore(void)
{
  Mock.nrf_raal_critical_section_enter_IgnoreBool = (int)1;
}

void nrf_raal_critical_section_enter_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_critical_section_enter_CALL_INSTANCE));
  CMOCK_nrf_raal_critical_section_enter_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_critical_section_enter_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_critical_section_enter_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_critical_section_enter_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void nrf_raal_critical_section_enter_StubWithCallback(CMOCK_nrf_raal_critical_section_enter_CALLBACK Callback)
{
  Mock.nrf_raal_critical_section_enter_CallbackFunctionPointer = Callback;
}

void nrf_raal_critical_section_exit(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nrf_raal_critical_section_exit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_critical_section_exit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nrf_raal_critical_section_exit_CallInstance);
  Mock.nrf_raal_critical_section_exit_CallInstance = CMock_Guts_MemNext(Mock.nrf_raal_critical_section_exit_CallInstance);
  if (Mock.nrf_raal_critical_section_exit_IgnoreBool)
  {
    return;
  }
  if (Mock.nrf_raal_critical_section_exit_CallbackFunctionPointer != NULL)
  {
    Mock.nrf_raal_critical_section_exit_CallbackFunctionPointer(Mock.nrf_raal_critical_section_exit_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'nrf_raal_critical_section_exit' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_critical_section_exit' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'nrf_raal_critical_section_exit' called later than expected.");
}

void nrf_raal_critical_section_exit_CMockIgnore(void)
{
  Mock.nrf_raal_critical_section_exit_IgnoreBool = (int)1;
}

void nrf_raal_critical_section_exit_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nrf_raal_critical_section_exit_CALL_INSTANCE));
  CMOCK_nrf_raal_critical_section_exit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nrf_raal_critical_section_exit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.nrf_raal_critical_section_exit_CallInstance = CMock_Guts_MemChain(Mock.nrf_raal_critical_section_exit_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void nrf_raal_critical_section_exit_StubWithCallback(CMOCK_nrf_raal_critical_section_exit_CALLBACK Callback)
{
  Mock.nrf_raal_critical_section_exit_CallbackFunctionPointer = Callback;
}

/* lint -restore */
