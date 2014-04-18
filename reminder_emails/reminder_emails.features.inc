<?php
/**
 * @file
 * reminder_emails.features.inc
 */

/**
 * Implements hook_views_api().
 */
function reminder_emails_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function reminder_emails_flag_default_flags() {
  $flags = array();
  // Exported flag: "Cancel this registration".
  $flags['cancel_registration'] = array(
    'entity_type' => 'node',
    'title' => 'Cancel this registration',
    'global' => 1,
    'types' => array(
      0 => 'registration',
    ),
    'flag_short' => 'cancel',
    'flag_long' => 'Cancel this registration',
    'flag_message' => 'This registration has been canceled for [node:title]',
    'unflag_short' => 'uncancel',
    'unflag_long' => 'Restore this registration',
    'unflag_message' => 'This registration has been restored for [node:title]',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to cancel the registration for [node:title]?',
    'unflag_confirmation' => 'Are you sure you want to restore this registration for [node:title]?',
    'module' => 'reminder_emails',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
