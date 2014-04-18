<?php
/**
 * @file
 * course_feeds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function course_feeds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function course_feeds_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function course_feeds_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('This is the course for the course listings.'),
      'has_title' => '1',
      'title_label' => t('course_title'),
      'help' => '',
    ),
  );
  return $items;
}
