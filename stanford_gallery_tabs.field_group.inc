<?php
/**
 * @file
 * stanford_gallery_tabs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_gallery_tabs_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_su_tab|node|stanford_gallery_tab|form';
  $field_group->group_name = 'group_su_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_gallery_tab';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tab',
    'weight' => '1',
    'children' => array(
      0 => 'field_su_gt_name',
      1 => 'field_su_gt_job_title',
      2 => 'field_su_gt_department',
      3 => 'field_su_gt_quotation',
      4 => 'field_su_gt_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Tab',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-su-tab field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_su_tab|node|stanford_gallery_tab|form'] = $field_group;

  return $export;
}
