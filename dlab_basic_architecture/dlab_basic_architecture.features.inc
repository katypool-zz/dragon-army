<?php
/**
 * @file
 * dlab_basic_architecture.features.inc
 */

/**
 * Implements hook_node_info().
 */
function dlab_basic_architecture_node_info() {
  $items = array(
    'admin_page' => array(
      'name' => t('Admin Page'),
      'base' => 'node_content',
      'description' => t('This is a page for site moderators and administrators that cannot be seen by the public.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'campus_resources' => array(
      'name' => t('Campus Resources'),
      'base' => 'node_content',
      'description' => t('Campus Resources'),
      'has_title' => '1',
      'title_label' => t('Campus Resources'),
      'help' => '',
    ),
    'consultation' => array(
      'name' => t('Consultation'),
      'base' => 'node_content',
      'description' => t('Use this for consulting AFTER you\'ve added the individual consultant as a "Person" content type first.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'contactus' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => t('This contains a list of useful contacts'),
      'has_title' => '1',
      'title_label' => t('Contacts'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'icons' => array(
      'name' => t('Icons'),
      'base' => 'node_content',
      'description' => t('Upload training and other icons here.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'landing_page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('This content type is for blurbs, pictures and links of D-Lab offerings that will be shown on landing pages for "services," "resources," etc. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'registration' => array(
      'name' => t('Registration'),
      'base' => 'node_content',
      'description' => t('event registration intake (workshops, consulting, etc.)'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => t('A database of resources for developing skills in coding, analysis, etc.'),
      'has_title' => '1',
      'title_label' => t('Resource'),
      'help' => '',
    ),
    'slide' => array(
      'name' => t('Slide'),
      'base' => 'node_content',
      'description' => t('Content type to create new slides, by Rochelle. Note that this is the new slider content type we are using as of August 2013.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'staff' => array(
      'name' => t('People'),
      'base' => 'node_content',
      'description' => t('This page contains staff details. Includes information on consultants and trainers as well. '),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'support_ticket' => array(
      'name' => t('Support Ticket'),
      'base' => 'node_content',
      'description' => t('This is the support/intake ticket content type for site communication.'),
      'has_title' => '1',
      'title_label' => t('Subject'),
      'help' => '',
    ),
    'training' => array(
      'name' => t('Training'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Training'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'working_groups' => array(
      'name' => t('Working Groups'),
      'base' => 'node_content',
      'description' => t('Use this for DLab working groups. These are student-run groups with repeating dates (e.g. Wednesday, 1-2pm).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
