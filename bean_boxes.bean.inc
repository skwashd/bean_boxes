<?php
/**
 * @file
 * bean_boxes.bean.inc
 */

/**
 * Implementation of hook_bean_admin_ui_types().
 */
function bean_boxes_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass;
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'box';
  $bean_type->label = 'box';
  $bean_type->options = '';
  $bean_type->description = 'Editable content boxes.';
  $export['box'] = $bean_type;

  return $export;
}
