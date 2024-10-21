/* -*- Mode: C ; c-basic-offset: 2 -*- */
/*****************************************************************************
 *
 *   This file is part of lv2dynparam host library
 *
 *   Copyright (C) 2006,2007,2008,2009 Nedko Arnaudov <nedko@arnaudov.name>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; version 2 of the License
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *****************************************************************************/

/**
 * @file host.h
 * @brief Interface to LV2 dynparam extension host helper library
 */

#ifndef DYNPARAM_H__5090F477_0BE7_439F_BF1D_F2EB78822760__INCLUDED
#define DYNPARAM_H__5090F477_0BE7_439F_BF1D_F2EB78822760__INCLUDED

/** handle to host helper library instance */
typedef void * lv2dynparam_host_instance;

/** handle to host helper library representation of parameter */
typedef void * lv2dynparam_host_parameter;

/** handle to host helper library representation of group */
typedef void * lv2dynparam_host_group;

/** handle to host helper library representation of command */
typedef void * lv2dynparam_host_command;

#define LV2DYNPARAM_PARAMETER_TYPE_UNKNOWN   0
#define LV2DYNPARAM_PARAMETER_TYPE_FLOAT     1
#define LV2DYNPARAM_PARAMETER_TYPE_INT       2
#define LV2DYNPARAM_PARAMETER_TYPE_NOTE      3
#define LV2DYNPARAM_PARAMETER_TYPE_STRING    4
#define LV2DYNPARAM_PARAMETER_TYPE_FILENAME  5
#define LV2DYNPARAM_PARAMETER_TYPE_BOOLEAN   6
#define LV2DYNPARAM_PARAMETER_TYPE_ENUM      7

union lv2dynparam_host_parameter_value
{
  bool boolean;
  float fpoint;
  signed int integer;
  unsigned int enum_selected_index;
  char * string;
};

union lv2dynparam_host_parameter_range
{
  struct
  {
    float min;
    float max;
  } fpoint;
  struct
  {
    signed int min;
    signed int max;
  } integer;
  struct
  {
    char ** values;
    unsigned int values_count;
  } enumeration;
};

/**
 * Typedef for callback function to be called when new parameter is created.
 *
 * @param instance_context User context associated with instance,
 * as supplied previously to lv2dynparam_host_attach()
 * @param parameter_handle Handle to host helper library representation of
 * parameter that was created
 * @param parameter_context_ptr Pointer to variable to store the user context
 * user context associated with the created parameter
 */
typedef
void
(* lv2dynparam_parameter_created)(
  void * instance_context,
  lv2dynparam_host_parameter parameter_handle,
  unsigned int parameter_type,
  const char * parameter_name,
  void ** parameter_context_ptr);

typedef
void
(* lv2dynparam_parameter_value_change_context)(
  void * instance_context,
  void * parameter_context,
  void * value_change_context);

/**
 * Typedef for callback function to be called when parameter is being destroyed.
 *
 * @param instance_context user context associated with instance,
 * as supplied previously to lv2dynparam_host_attach()
 * @param parameter_context user context associated with the parameter being destroyed.
 */
typedef
void
(* lv2dynparam_parameter_destroying)(
  void * instance_context,
  void * parameter_context);

/**
 * Call this function to attach dynparam host helper library to particular plugin.
 * parameter_created_callback and parameter_destroying_callback are optional
 * but if supplied at all, both must be supplied.
 * Must be called from the UI thread.
 * This function may sleep/lock.
 *
 * @param lv2descriptor LV2 descriptor of plugin to attach to.
 * @param lv2instance handle to LV2 plugin instance.
 * @param rtmempool_ptr pointer to rt-capable memory pool.
 * @param instance_context user context to be associated with instance
 * @param parameter_created_callback Callback to be called when parameter is created. Can be NULL.
 * @param parameter_destroying_callback Callback to be called when parameter is being destroyed. Can be NULL.
 * @param instance_ptr Pointer to variable receiving handle to
 * host helper library instance.
 *
 * @return Success status
 * @retval true - success
 * @retval false - error
 */
bool
lv2dynparam_host_attach(
  const LV2_Descriptor * lv2descriptor,
  LV2_Handle lv2instance,
  struct lv2_rtsafe_memory_pool_provider * rtmempool_ptr,
  void * instance_context,
  lv2dynparam_parameter_created parameter_created_callback,
  lv2dynparam_parameter_destroying parameter_destroying_callback,
  lv2dynparam_parameter_value_change_context parameter_value_change_context,
  lv2dynparam_host_instance * instance_ptr);

/**
 * Call this function to deattach dynparam host helper library from particular plugin.
 * Must be called from the UI thread.
 * This function may sleep/lock.
 *
 * @param instance Handle to instance received from lv2dynparam_host_attach()
 */
void
lv2dynparam_host_detach(
  lv2dynparam_host_instance instance);

/**
 * Call this function to issue pending calls to plugin.
 * Must be called from from audio/midi realtime thread.
 * This function will not sleep/lock.
 *
 * @param instance Handle to instance received from lv2dynparam_host_attach()
 */
void
lv2dynparam_host_realtime_run(
  lv2dynparam_host_instance instance);

/**
 * Call this function to issue pending calls to UI.
 * Must be called from the UI thread.
 * This function may sleep/lock.
 *
 * @param instance Handle to instance received from lv2dynparam_host_attach()
 */
void
lv2dynparam_host_ui_run(
  lv2dynparam_host_instance instance);

/**
 * Call this function to trigger dynparams appear.
 * Must be called from from the UI thread.
 * This function may sleep/lock.
 *
 * @param instance Handle to instance received from lv2dynparam_host_attach()
 */
void
lv2dynparam_host_ui_on(
  lv2dynparam_host_instance instance);

/**
 * Call this function to trigger dynparams disappear.
 * Must be called from from the UI thread.
 * This function may sleep/lock.
 *
 * @param instance Handle to instance received from lv2dynparam_host_attach()
 */
void
lv2dynparam_host_ui_off(
  lv2dynparam_host_instance instance);

/**
 * Callback called from UI thread to notify UI about group appear.
 *
 * @param group_handle handle to host helper library representation of
 * group that appeared
 * @param instance_context user context associated with instance,
 * as supplied previously to lv2dynparam_host_attach()
 * @param parent_group_ui_context user context of parent group, NULL for root group.
 * @param group_name name of group that is appearing
 * @param hints_ptr Pointer to group hints.
 * @param group_ui_context Pointer to variable receiving UI context of appeared group.
 */
void
dynparam_ui_group_appeared(
  lv2dynparam_host_group group_handle,
  void * instance_context,
  void * parent_group_ui_context,
  const char * group_name,
  const struct lv2dynparam_hints * hints_ptr,
  void ** group_ui_context);

/**
 * Callback called from UI thread to notify UI about group disappear.
 *
 * @param instance_context user context associated with instance,
 * as supplied previously to lv2dynparam_host_attach()
 * @param parent_group_ui_context user context of parent group, NULL for root group.
 * @param group_ui_context user context of group that disappeared.
 */
void
dynparam_ui_group_disappeared(
  void * instance_context,
  void * parent_group_ui_context,
  void * group_ui_context);

/**
 * Callback called from UI thread to notify UI about command appear.
 *
 * @param command_handle handle to host helper library representation of
 * command that appeared
 * @param instance_context user context associated with instance,
 * as supplied previously to lv2dynparam_host_attach()
 * @param group_ui_context user context of parent group, NULL for root group.
 * @param command_name name of command that is appearing
 * @param hints_ptr Pointer to command hints.
 * @param command_ui_context Pointer to variable receiving UI context of appeared command.
 */
void
dynparam_ui_command_appeared(
  lv2dynparam_host_command command_handle,
  void * instance_context,
  void * group_ui_context,
  const char * command_name,
  const struct lv2dynparam_hints * hints_ptr,
  void ** command_ui_context);

/**
 * Callback called from UI thread to notify UI about command disappear.
 *
 * @param instance_context user context associated with instance,
 * as supplied previously to lv2dynparam_host_attach()
 * @param parent_group_ui_context user context of parent group, NULL for root group.
 * @param command_ui_context user context of command that disappeared.
 */
void
dynparam_ui_command_disappeared(
  void * instance_context,
  void * parent_group_ui_context,
  void * command_ui_context);

/**
 * Callback called from UI thread to notify UI about parameter appear.
 *
 * @param parameter_handle Handle to host helper library representation of
 * parameter that appeared
 * @param instance_context user context associated with instance,
 * as supplied previously to lv2dynparam_host_attach()
 * @param group_ui_context User context of parent group, NULL for root group.
 * @param parameter_name Name of parameter that is appearing
 * @param hints_ptr Pointer to parameter hints.
 * @param value Initial value of the appearing parameter
 * @param parameter_ui_context Pointer to variable receiving UI context of appeared parameter.
 */
void
dynparam_ui_parameter_appeared(
  lv2dynparam_host_parameter parameter_handle,
  void * instance_context,
  void * group_ui_context,
  unsigned int parameter_type,
  const char * parameter_name,
  const struct lv2dynparam_hints * hints_ptr,
  union lv2dynparam_host_parameter_value value,
  union lv2dynparam_host_parameter_range range,
  void * parameter_context,
  void ** parameter_ui_context);

/**
 * Callback called from UI thread to notify UI about parameter disappear.
 *
 * @param instance_context user context associated with instance,
 * as supplied previously to lv2dynparam_host_attach()
 * @param parent_group_ui_context user context of parent group, NULL for root group.
 * @param parameter_ui_context user context of parameter that disappeared.
 */
void
dynparam_ui_parameter_disappeared(
  void * instance_context,
  void * parent_group_ui_context,
  unsigned int parameter_type,
  void * parameter_context,
  void * parameter_ui_context);

/**
 * Call this function to change parameter value.
 * dynparam_parameter_value_changed() will be call will be scheduled
 * Must be called from from audio/midi realtime thread.
 * This function will not sleep/lock.
 *
 * @param instance Handle to instance received from lv2dynparam_host_attach()
 * @param parameter_handle handle of parameter which value will be changed
 * @param value the new value
 */
void
lv2dynparam_parameter_change_rt(
  lv2dynparam_host_instance instance,
  lv2dynparam_host_parameter parameter_handle,
  union lv2dynparam_host_parameter_value value);

/**
 * Call this function to change parameter value.
 * dynparam_parameter_value_changed() will not be called
 * Must be called from the UI thread.
 * This function may sleep/lock.
 *
 * @param instance Handle to instance received from lv2dynparam_host_attach()
 * @param parameter_handle handle of parameter which value will be changed
 * @param value the new value
 */
void
lv2dynparam_parameter_change(
  lv2dynparam_host_instance instance,
  lv2dynparam_host_parameter parameter_handle,
  union lv2dynparam_host_parameter_value value);

/**
 * Callback called from UI thread to notify host about parameter value change.
 *
 */
void
dynparam_ui_parameter_value_changed(
  void * instance_context,
  void * parameter_context,
  void * parameter_ui_context,
  union lv2dynparam_host_parameter_value value);

/**
 * Typedef for callback function to be called from dynparam_get_parameters()
 *
 * @param context User context, as supplied as dynparam_get_parameters() parameter
 * @param parameter_name Parameter name
 * @param parameter_value Parameter value, as string
 */
typedef
void
(* lv2dynparam_parameter_get_callback)(
  void * context,
  void * parameter_context,
  const char * parameter_name,
  const char * parameter_value);

/**
 * Call this funtion to get parameters of plugin, as pairs of parameter name and value strings.
 * Must be called from the UI thread.
 * This function may sleep/lock.
 *
 * @param instance Handle to instance received from lv2dynparam_host_attach()
 * @param callback Callback to be called for each parameter
 * @param context User context to be supplied as parameter when callback is called
 */
void
lv2dynparam_get_parameters(
  lv2dynparam_host_instance instance,
  lv2dynparam_parameter_get_callback callback,
  void * context);

/**
 * Call this function to set parameter of plugin, as pair of parameter name and value strings.
 * Must be called from the UI thread.
 * This function may sleep/lock.
 *
 * @param instance Handle to instance received from lv2dynparam_host_attach()
 * @param parameter_name Parameter name
 * @param parameter_value Parameter value, as string
 */
void
lv2dynparam_set_parameter(
  lv2dynparam_host_instance instance,
  const char * parameter_name,
  const char * parameter_value,
  void * context);

#endif /* #ifndef DYNPARAM_H__5090F477_0BE7_439F_BF1D_F2EB78822760__INCLUDED */
