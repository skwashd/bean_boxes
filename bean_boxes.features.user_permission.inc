<?php
/**
 * @file
 * bean_boxes.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function bean_boxes_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer bean types
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: administer beans
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: create any box bean
  $permissions['create any box bean'] = array(
    'name' => 'create any box bean',
    'roles' => array(),
  );

  // Exported permission: delete any box bean
  $permissions['delete any box bean'] = array(
    'name' => 'delete any box bean',
    'roles' => array(),
  );

  // Exported permission: edit any box bean
  $permissions['edit any box bean'] = array(
    'name' => 'edit any box bean',
    'roles' => array(),
  );

  // Exported permission: edit bean view mode
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: view any box bean
  $permissions['view any box bean'] = array(
    'name' => 'view any box bean',
    'roles' => array(),
  );

  return $permissions;
}
