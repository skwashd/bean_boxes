<?php

/**
 * Converts a boxes block to a BEAN block.
 */
function _box_to_bean($id, $box) {

  drush_print("Converting $id");

  $view_mode = 'default';
  $label = $id;
  
  $bean = bean_create(array('type' => 'box'));
  $bean->label = $label;
  $bean->description = $box->description;
  $bean->title = $box->title;
  $bean->data = array('view_mode' => $view_mode);
  $bean->delta = $label;
  $bean->view_mode = $view_mode;
  $bean->field_box_body = array(
    LANGUAGE_NONE => array(
      array(
        'value' => $box->options['body']['value'],
        'format' => $box->options['body']['format'],
      ),
    ),
  );
  bean_save($bean);
}

drush_print("Processing boxes");
$boxes = boxes_box_load();
foreach ($boxes as $id => $box) {
  _box_to_bean($id, $box);
}
drush_print("Boxes Completed");

drush_print("Processing contexts");
$contexts = context_load();
foreach ($contexts as $id => $context) {
  if (empty($context->reactions['block']['blocks'])) {
    continue;
  }

  foreach ($context->reactions['block']['blocks'] as $delta => $block) {
    if ('boxes' != $block['module']) {
      continue;
    }

    drush_print("Converting $id");

    $new_delta = preg_replace('/boxes-(.+)/', 'bean-\\1', $delta);
    unset($context->reactions['block']['blocks'][$delta]);
    $block['module'] = 'bean';
    $context->reactions['block']['blocks'][$new_delta] = $block;
    context_save($context);
  }
}
drush_print("Contexts Completed");

