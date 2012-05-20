<?php
/**
 * @file
 * bean_boxes.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function bean_boxes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
