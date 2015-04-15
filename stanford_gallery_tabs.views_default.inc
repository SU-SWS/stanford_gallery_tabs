<?php
/**
 * @file
 * stanford_gallery_tabs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_gallery_tabs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'gallery_tabs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Gallery Tabs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Gallery Tabs - Tabs List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Department */
  $handler->display->display_options['fields']['field_su_gt_department']['id'] = 'field_su_gt_department';
  $handler->display->display_options['fields']['field_su_gt_department']['table'] = 'field_data_field_su_gt_department';
  $handler->display->display_options['fields']['field_su_gt_department']['field'] = 'field_su_gt_department';
  $handler->display->display_options['fields']['field_su_gt_department']['label'] = '';
  $handler->display->display_options['fields']['field_su_gt_department']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_su_gt_department']['element_label_colon'] = FALSE;
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_su_gt_job_title']['id'] = 'field_su_gt_job_title';
  $handler->display->display_options['fields']['field_su_gt_job_title']['table'] = 'field_data_field_su_gt_job_title';
  $handler->display->display_options['fields']['field_su_gt_job_title']['field'] = 'field_su_gt_job_title';
  $handler->display->display_options['fields']['field_su_gt_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_su_gt_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_su_gt_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_su_gt_name']['id'] = 'field_su_gt_name';
  $handler->display->display_options['fields']['field_su_gt_name']['table'] = 'field_data_field_su_gt_name';
  $handler->display->display_options['fields']['field_su_gt_name']['field'] = 'field_su_gt_name';
  $handler->display->display_options['fields']['field_su_gt_name']['label'] = '';
  $handler->display->display_options['fields']['field_su_gt_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_su_gt_name']['element_label_colon'] = FALSE;
  /* Field: Content: Quotation */
  $handler->display->display_options['fields']['field_su_gt_quotation']['id'] = 'field_su_gt_quotation';
  $handler->display->display_options['fields']['field_su_gt_quotation']['table'] = 'field_data_field_su_gt_quotation';
  $handler->display->display_options['fields']['field_su_gt_quotation']['field'] = 'field_su_gt_quotation';
  $handler->display->display_options['fields']['field_su_gt_quotation']['label'] = '';
  $handler->display->display_options['fields']['field_su_gt_quotation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_su_gt_quotation']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="su-gallery-tab">
  <div class="su-gallery-tab-quote">
    [field_su_gt_quotation]
  </div>
  <div class="su-gallery-tab-name">
    [field_su_gt_name]
  </div>
  <div class="su-gallery-tab-job-title">
    [field_su_gt_job_title]
  </div>
  <div class="su-gallery-tab-department">
    [field_su_gt_department]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_gallery_tab' => 'stanford_gallery_tab',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Tab List';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gallery Tabs - Image';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_su_gt_image']['id'] = 'field_su_gt_image';
  $handler->display->display_options['fields']['field_su_gt_image']['table'] = 'field_data_field_su_gt_image';
  $handler->display->display_options['fields']['field_su_gt_image']['field'] = 'field_su_gt_image';
  $handler->display->display_options['fields']['field_su_gt_image']['label'] = '';
  $handler->display->display_options['fields']['field_su_gt_image']['element_class'] = 'su-gallery-image';
  $handler->display->display_options['fields']['field_su_gt_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_su_gt_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_su_gt_image']['settings'] = array(
    'image_style' => 'caw-large-landscape',
    'image_link' => '',
  );
  $handler->display->display_options['block_description'] = 'Images';
  $translatables['gallery_tabs'] = array(
    t('Master'),
    t('Gallery Tabs - Tabs List'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<div class="su-gallery-tab">
  <div class="su-gallery-tab-quote">
    [field_su_gt_quotation]
  </div>
  <div class="su-gallery-tab-name">
    [field_su_gt_name]
  </div>
  <div class="su-gallery-tab-job-title">
    [field_su_gt_job_title]
  </div>
  <div class="su-gallery-tab-department">
    [field_su_gt_department]
  </div>
</div>'),
    t('Block'),
    t('Tab List'),
    t('Gallery Tabs - Image'),
    t('Images'),
  );
  $export['gallery_tabs'] = $view;

  return $export;
}
