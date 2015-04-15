<?php
/**
 * @file
 * stanford_gallery_tabs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_gallery_tabs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_gallery_tabs_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_gallery_tabs_node_info() {
  $items = array(
    'stanford_gallery_tab' => array(
      'name' => t('Gallery Tab'),
      'base' => 'node_content',
      'description' => t('A tab for the gallery tab feature. Includes a large image, a persons name, their title and department, and a quotation.'),
      'has_title' => '1',
      'title_label' => t('Administrative Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
