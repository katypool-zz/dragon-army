<?php
/**
 * @file
 * course_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function course_feeds_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'course_list';
  $feeds_importer->config = array(
    'name' => 'course_list',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => 'TAB',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '99',
        'mappings' => array(
          0 => array(
            'source' => 'DEPT',
            'target' => 'field_department',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          1 => array(
            'source' => 'COURSE',
            'target' => 'field_course_code_text',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'CCN',
            'target' => 'field_ccn',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'TITLE',
            'target' => 'title',
            'unique' => 0,
          ),
          4 => array(
            'source' => 'DESCRIPTION',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'COURSEN',
            'target' => 'field_course_number',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'TERM',
            'target' => 'field_term',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'INSTRUCTOR',
            'target' => 'field_instructor',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'full_html',
        'bundle' => 'course',
        'authorize' => 0,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['course_list'] = $feeds_importer;

  return $export;
}
