/* -*- Mode: C ; c-basic-offset: 2 -*- */
/*****************************************************************************
 *
 *   This file is part of lv2dynparam plugin library
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
 * @file plugin.h
 * @brief Interface to LV2 dynparam extension plugin helper library
 */

#ifndef DYNPARAM_H__84DA2DA3_61BD_45AC_B202_6A08F27D56F5__INCLUDED
#define DYNPARAM_H__84DA2DA3_61BD_45AC_B202_6A08F27D56F5__INCLUDED

/**
 * Call this function to obtain pointer to data for LV2 dynparam extension.
 * This pointer must be returned by LV2 extension_data() called for LV2DYNPARAM_URI
 *
 * @return The extension data for LV2 dynparam extension.
 */
const void *
get_lv2dynparam_plugin_extension_data(void);

/** handle to plugin helper library instance */
typedef void * lv2dynparam_plugin_instance;

/** handle to plugin helper library representation of parameter */
typedef void * lv2dynparam_plugin_parameter;

/** handle to plugin helper library representation of group */
typedef void * lv2dynparam_plugin_group;

/**
 * Call this function to instantiate LV2 dynparams extension for particular plugin.
 * This function should be called from LV2 instatiate() function.
 *
 * @param instance Handle of LV2 plugin instance for which extension is being initialized.
 * @param host_features_ptr_ptr host features as provided to LV2 instantiate() function
 * @param root_group_name Name of the root group
 * @param instance_ptr Pointer to variable receiving handle to plugin helper library instance.
 *
 * @return Success status
 * @retval true - success
 * @retval false - error
 */
bool
lv2dynparam_plugin_instantiate(
  LV2_Handle instance,
  const LV2_Feature * const * host_features_ptr_ptr,
  const char * root_group_name,
  lv2dynparam_plugin_instance * instance_ptr);

/**
 * Call this function to cleanup previously instatiated extension for particular plugin.
 * This function should be called from LV2 cleanup() function.
 *
 * @param instance Handle to instance received from lv2dynparam_plugin_instantiate()
 */
void
lv2dynparam_plugin_cleanup(
  lv2dynparam_plugin_instance instance);

/**
 * Type for callback function to be called by helper library when boolean parameter value is changed by host.
 * Callee is not allowed to sleep/lock in this callback.
 *
 * @param context context supplied by plugin when parameter was added to helper library
 * @param value new value of changed parameter
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
typedef bool
(*lv2dynparam_plugin_param_boolean_changed)(
  void * context,
  bool value);

/**
 * Type for callback function to be called by helper library when float parameter value is changed by host.
 * Callee is not allowed to sleep/lock in this callback.
 *
 * @param context context supplied by plugin when parameter was added to helper library
 * @param value new value of changed parameter
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
typedef bool
(*lv2dynparam_plugin_param_float_changed)(
  void * context,
  float value);

/**
 * Type for callback function to be called by helper library when enumeration parameter value is changed by host.
 * Callee is not allowed to sleep/lock in this callback.
 *
 * @param context context supplied by plugin when parameter was added to helper library
 * @param value new value of changed parameter
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
typedef bool
(*lv2dynparam_plugin_param_enum_changed)(
  void * context,
  const char * value,
  unsigned int value_index);

/**
 * Type for callback function to be called by helper library when integer parameter value is changed by host.
 * Callee is not allowed to sleep/lock in this callback.
 *
 * @param context context supplied by plugin when parameter was added to helper library
 * @param value new value of changed parameter
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
typedef bool
(*lv2dynparam_plugin_param_int_changed)(
  void * context,
  int value);

/**
 * Call this function to add new group.
 * This function will not sleep/lock. It is safe to call it from callbacks
 * for parameter changes and command executions.
 *
 * @param instance Handle to instance received from lv2dynparam_plugin_instantiate()
 * @param parent_group Parent group, NULL for root group
 * @param name Human readble name of group to add
 * @param hints_ptr Pointer to group hints. Can be NULL (no hints).
 * @param group_ptr Pointer to variable receiving handle to plugin helper library representation of group
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
bool
lv2dynparam_plugin_group_add(
  lv2dynparam_plugin_instance instance,
  lv2dynparam_plugin_group parent_group,
  const char * name,
  const struct lv2dynparam_hints * hints_ptr,
  lv2dynparam_plugin_group * group_ptr);

/**
 * Call this function to add new boolean parameter.
 * This function will not sleep/lock. It is safe to call it from callbacks
 * for parameter changes and command executions.
 *
 * @param instance Handle to instance received from lv2dynparam_plugin_instantiate()
 * @param group Parent group, NULL for root group
 * @param name Human readble name of group to add
 * @param hints_ptr Pointer to group hints. Can be NULL (no hints).
 * @param value initial value of the parameter
 * @param callback callback to be called when host requests value change
 * @param callback_context context to be supplied as parameter to function supplied by @c callback parameter
 * @param param_ptr Pointer to variable receiving handle to plugin helper library representation of parameter
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
bool
lv2dynparam_plugin_param_boolean_add(
  lv2dynparam_plugin_instance instance,
  lv2dynparam_plugin_group group,
  const char * name,
  const struct lv2dynparam_hints * hints_ptr,
  int value,
  lv2dynparam_plugin_param_boolean_changed callback,
  void * callback_context,
  lv2dynparam_plugin_parameter * param_ptr);

/**
 * Call this function to add new float parameter.
 * This function will not sleep/lock. It is safe to call it from callbacks
 * for parameter changes and command executions.
 *
 * @param instance Handle to instance received from lv2dynparam_plugin_instantiate()
 * @param group Parent group, NULL for root group
 * @param name Human readble name of group to add
 * @param hints_ptr Pointer to group hints. Can be NULL (no hints).
 * @param value initial value of the parameter
 * @param min minimum allowed value of the parameter
 * @param max maximum allowed value of the parameter
 * @param callback callback to be called when host requests value change
 * @param callback_context context to be supplied as parameter to function supplied by @c callback parameter
 * @param param_ptr Pointer to variable receiving handle to plugin helper library representation of parameter
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
bool
lv2dynparam_plugin_param_float_add(
  lv2dynparam_plugin_instance instance,
  lv2dynparam_plugin_group group,
  const char * name,
  const struct lv2dynparam_hints * hints_ptr,
  float value,
  float min,
  float max,
  lv2dynparam_plugin_param_float_changed callback,
  void * callback_context,
  lv2dynparam_plugin_parameter * param_ptr);

/**
 * Call this function to add new enumeration parameter.
 * This function will not sleep/lock. It is safe to call it from callbacks
 * for parameter changes and command executions.
 *
 * @param instance Handle to instance received from lv2dynparam_plugin_instantiate()
 * @param group Parent group, NULL for root group
 * @param name Human readble name of group to add
 * @param hints_ptr Pointer to group hints. Can be NULL (no hints).
 * @param values_ptr_ptr Pointer to array of strings containing enumeration valid values.
 * @param values_count Number of strings in the array pointed by the @c values_ptr_ptr parameter
 * @param initial_value_index Index in array pointed by the @c values_ptr_ptr parameter, specifying initial value
 * @param callback callback to be called when host requests value change
 * @param callback_context context to be supplied as parameter to function supplied by @c callback parameter
 * @param param_ptr Pointer to variable receiving handle to plugin helper library representation of parameter
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
bool
lv2dynparam_plugin_param_enum_add(
  lv2dynparam_plugin_instance instance,
  lv2dynparam_plugin_group group,
  const char * name,
  const struct lv2dynparam_hints * hints_ptr,
  const char ** values_ptr_ptr,
  unsigned int values_count,
  unsigned int initial_value_index,
  lv2dynparam_plugin_param_enum_changed callback,
  void * callback_context,
  lv2dynparam_plugin_parameter * param_ptr);

/**
 * Call this function to add new integer parameter.
 * This function will not sleep/lock. It is safe to call it from callbacks
 * for parameter changes and command executions.
 *
 * @param instance Handle to instance received from lv2dynparam_plugin_instantiate()
 * @param group Parent group, NULL for root group
 * @param name Human readble name of group to add
 * @param hints_ptr Pointer to group hints. Can be NULL (no hints).
 * @param value initial value of the parameter
 * @param min minimum allowed value of the parameter
 * @param max maximum allowed value of the parameter
 * @param callback callback to be called when host requests value change
 * @param callback_context context to be supplied as parameter to function supplied by @c callback parameter
 * @param param_ptr Pointer to variable receiving handle to plugin helper library representation of parameter
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
bool
lv2dynparam_plugin_param_int_add(
  lv2dynparam_plugin_instance instance,
  lv2dynparam_plugin_group group,
  const char * name,
  const struct lv2dynparam_hints * hints_ptr,
  signed int value,
  signed int min,
  signed int max,
  lv2dynparam_plugin_param_int_changed callback,
  void * callback_context,
  lv2dynparam_plugin_parameter * param_ptr);

/**
 * Call this function to remove parameter
 *
 * @param instance Handle to instance received from lv2dynparam_plugin_instantiate()
 * @param param handle to plugin helper library representation of parameter to remove
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
bool
lv2dynparam_plugin_param_remove(
  lv2dynparam_plugin_instance instance,
  lv2dynparam_plugin_parameter param);

/**
 * Call this function to change boolean parameter value
 *
 * @param instance Handle to instance received from lv2dynparam_plugin_instantiate()
 * @param param handle to plugin helper library representation of parameter to change
 * @param value new value
 *
 * @return Success status
 * @retval true - success
 * @retval false - error, try later
 */
bool
lv2dynparam_plugin_param_boolean_change(
  lv2dynparam_plugin_instance instance,
  lv2dynparam_plugin_parameter param,
  bool value);

#endif /* #ifndef DYNPARAM_H__84DA2DA3_61BD_45AC_B202_6A08F27D56F5__INCLUDED */
