<?php
/**
 * @file
 * consultation_request.features.inc
 */

/**
 * Implements hook_views_api().
 */
function consultation_request_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function consultation_request_flag_default_flags() {
  $flags = array();
  // Exported flag: "Status".
  $flags['status'] = array(
    'entity_type' => 'node',
    'title' => 'Status',
    'global' => '1',
    'types' => array(
      0 => 'support_ticket',
      1 => 'webform',
    ),
    'flag_short' => 'Mark this resolved',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Mark this unresolved',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'api_version' => 3,
    'module' => 'consultation_request',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
