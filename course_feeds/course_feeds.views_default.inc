<?php
/**
 * @file
 * course_feeds.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function course_feeds_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'course_by_department';
  $view->description = 'A view that lists all courses by department based on the URL (passed value of the real taxonomy term name)';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'course-by-department';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'course-by-department';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: CCN */
  $handler->display->display_options['fields']['field_ccn']['id'] = 'field_ccn';
  $handler->display->display_options['fields']['field_ccn']['table'] = 'field_data_field_ccn';
  $handler->display->display_options['fields']['field_ccn']['field'] = 'field_ccn';
  $handler->display->display_options['fields']['field_ccn']['exclude'] = TRUE;
  /* Field: Content: Term (SP for Spring; FL for Fall) */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['label'] = 'term (SP for Spring; FL for Fall)';
  $handler->display->display_options['fields']['field_term']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'http://osoc.berkeley.edu/OSOC/osoc?p_ccn=[field_ccn]&p_term=[field_term]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'course-title';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  /* Field: Content: Course Number */
  $handler->display->display_options['fields']['field_course_code_text']['id'] = 'field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['table'] = 'field_data_field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['field'] = 'field_course_code_text';
  /* Field: Content: Instructor */
  $handler->display->display_options['fields']['field_instructor']['id'] = 'field_instructor';
  $handler->display->display_options['fields']['field_instructor']['table'] = 'field_data_field_instructor';
  $handler->display->display_options['fields']['field_instructor']['field'] = 'field_instructor';
  /* Field: Content: Units */
  $handler->display->display_options['fields']['field_units']['id'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['table'] = 'field_data_field_units';
  $handler->display->display_options['fields']['field_units']['field'] = 'field_units';
  /* Field: Content: CCN */
  $handler->display->display_options['fields']['field_ccn_1']['id'] = 'field_ccn_1';
  $handler->display->display_options['fields']['field_ccn_1']['table'] = 'field_data_field_ccn';
  $handler->display->display_options['fields']['field_ccn_1']['field'] = 'field_ccn';
  /* Field: Content: Term (SP for Spring; FL for Fall) */
  $handler->display->display_options['fields']['field_term_1']['id'] = 'field_term_1';
  $handler->display->display_options['fields']['field_term_1']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term_1']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term_1']['label'] = 'Term';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'course-by-department/%';
  $export['course_by_department'] = $view;

  $view = new view();
  $view->name = 'course_list';
  $view->description = 'lists all courses in a list (content_type == course)';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course List';
  $handler->display->display_options['css_class'] = 'course-list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_department' => 'field_department',
    'field_course_code_text' => 'field_course_code_text',
    'field_ccn' => 'field_ccn',
    'field_units' => 'field_units',
    'field_instructor' => 'field_instructor',
    'title' => 'title',
    'field_course_number' => 'field_course_number',
    'field_description' => 'field_description',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_department' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_code_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ccn' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_units' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_instructor' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<b>Learning about what data- or method-oriented courses are available should be simple.</b> Because the Berkeley course catalog is hard to search, D-Lab has created listings of Berkeley graduate and undergraduate courses for Spring 2013 that cover methods, approaches, techniques, tools, software, or data relevant to data-intensive social science across departments and disciplines. We anticipate adding course listings for online courses and other resources. After searching, click on the course title for additional details.

Feedback? Please send to <a href="mailto:dlab@berkeley.edu">dlab@berkeley.edu</a><br></br><br></br>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'department' => 'department',
    'availability' => 0,
    'blog_categories' => 0,
    'data_resource_source' => 0,
    'event_host' => 0,
    'event_type' => 0,
    'job_seeking' => 0,
    'people_type' => 0,
    'portfolio_categories' => 0,
    'skills_tag' => 0,
    'support_ticket_status' => 0,
    'tags' => 0,
    'training_status' => 0,
    'training_type' => 0,
    'yes_no' => 0,
  );
  /* Field: Content: CCN */
  $handler->display->display_options['fields']['field_ccn']['id'] = 'field_ccn';
  $handler->display->display_options['fields']['field_ccn']['table'] = 'field_data_field_ccn';
  $handler->display->display_options['fields']['field_ccn']['field'] = 'field_ccn';
  $handler->display->display_options['fields']['field_ccn']['exclude'] = TRUE;
  /* Field: Content: Units */
  $handler->display->display_options['fields']['field_units']['id'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['table'] = 'field_data_field_units';
  $handler->display->display_options['fields']['field_units']['field'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['exclude'] = TRUE;
  /* Field: Content: Department */
  $handler->display->display_options['fields']['field_department']['id'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['table'] = 'field_data_field_department';
  $handler->display->display_options['fields']['field_department']['field'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_department']['alter']['path'] = 'course-by-department/[field_department]';
  $handler->display->display_options['fields']['field_department']['element_class'] = 'course-list-department';
  $handler->display->display_options['fields']['field_department']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Term (SP for Spring; FL for Fall) */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['label'] = '';
  $handler->display->display_options['fields']['field_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term']['element_label_colon'] = FALSE;
  /* Field: Content: Course Number */
  $handler->display->display_options['fields']['field_course_code_text']['id'] = 'field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['table'] = 'field_data_field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['field'] = 'field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['label'] = 'Course';
  $handler->display->display_options['fields']['field_course_code_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_code_text']['alter']['text'] = '[field_department]<br>[field_course_code_text]<br>[field_units] units';
  $handler->display->display_options['fields']['field_course_code_text']['alter']['make_link'] = TRUE;
  /* Field: Content: Instructor */
  $handler->display->display_options['fields']['field_instructor']['id'] = 'field_instructor';
  $handler->display->display_options['fields']['field_instructor']['table'] = 'field_data_field_instructor';
  $handler->display->display_options['fields']['field_instructor']['field'] = 'field_instructor';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'http://osoc.berkeley.edu/OSOC/osoc?p_ccn=[field_ccn]&p_term=[field_term]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: course_number */
  $handler->display->display_options['fields']['field_course_number']['id'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['fields']['field_course_number']['field'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['label'] = 'number';
  $handler->display->display_options['fields']['field_course_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '<br>[field_description]';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'course::field_term' => 'course::field_term',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_remove_canceled_users_from_count' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_send_feedback_email_part_1' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_send_feedback_email_part_2' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_reminder_email_1' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_reminder_email_2' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Department (field_department) */
  $handler->display->display_options['sorts']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['sorts']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['sorts']['field_department_tid']['field'] = 'field_department_tid';
  /* Sort criterion: Content: course_number (field_course_number) */
  $handler->display->display_options['sorts']['field_course_number_value']['id'] = 'field_course_number_value';
  $handler->display->display_options['sorts']['field_course_number_value']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['sorts']['field_course_number_value']['field'] = 'field_course_number_value';
  /* Sort criterion: Content: Course Number (field_course_code_text) */
  $handler->display->display_options['sorts']['field_course_code_text_value']['id'] = 'field_course_code_text_value';
  $handler->display->display_options['sorts']['field_course_code_text_value']['table'] = 'field_data_field_course_code_text';
  $handler->display->display_options['sorts']['field_course_code_text_value']['field'] = 'field_course_code_text_value';
  /* Sort criterion: Content: CCN (field_ccn) */
  $handler->display->display_options['sorts']['field_ccn_value']['id'] = 'field_ccn_value';
  $handler->display->display_options['sorts']['field_ccn_value']['table'] = 'field_data_field_ccn';
  $handler->display->display_options['sorts']['field_ccn_value']['field'] = 'field_ccn_value';
  /* Sort criterion: Content: Units (field_units) */
  $handler->display->display_options['sorts']['field_units_value']['id'] = 'field_units_value';
  $handler->display->display_options['sorts']['field_units_value']['table'] = 'field_data_field_units';
  $handler->display->display_options['sorts']['field_units_value']['field'] = 'field_units_value';
  $handler->display->display_options['sorts']['field_units_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Dept';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Description (field_description) */
  $handler->display->display_options['filters']['field_description_value']['id'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['table'] = 'field_data_field_description';
  $handler->display->display_options['filters']['field_description_value']['field'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_description_value']['group'] = 1;
  $handler->display->display_options['filters']['field_description_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_description_value']['expose']['operator_id'] = 'field_description_value_op';
  $handler->display->display_options['filters']['field_description_value']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['field_description_value']['expose']['operator'] = 'field_description_value_op';
  $handler->display->display_options['filters']['field_description_value']['expose']['identifier'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Semester (field_semester) */
  $handler->display->display_options['filters']['field_semester_value']['id'] = 'field_semester_value';
  $handler->display->display_options['filters']['field_semester_value']['table'] = 'field_data_field_semester';
  $handler->display->display_options['filters']['field_semester_value']['field'] = 'field_semester_value';
  $handler->display->display_options['filters']['field_semester_value']['value'] = array(
    'Spring 2014' => 'Spring 2014',
  );
  $handler->display->display_options['filters']['field_semester_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_semester_value']['expose']['operator_id'] = 'field_semester_value_op';
  $handler->display->display_options['filters']['field_semester_value']['expose']['label'] = 'Semester';
  $handler->display->display_options['filters']['field_semester_value']['expose']['operator'] = 'field_semester_value_op';
  $handler->display->display_options['filters']['field_semester_value']['expose']['identifier'] = 'field_semester_value';
  $handler->display->display_options['filters']['field_semester_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Term (SP for Spring; FL for Fall) (field_term) */
  $handler->display->display_options['filters']['field_term_value']['id'] = 'field_term_value';
  $handler->display->display_options['filters']['field_term_value']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_value']['field'] = 'field_term_value';
  $handler->display->display_options['filters']['field_term_value']['value'] = 'SP';
  $handler->display->display_options['filters']['field_term_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_value']['expose']['operator_id'] = 'field_term_value_op';
  $handler->display->display_options['filters']['field_term_value']['expose']['label'] = 'Term (SP for Spring; FL for Fall) (field_term)';
  $handler->display->display_options['filters']['field_term_value']['expose']['operator'] = 'field_term_value_op';
  $handler->display->display_options['filters']['field_term_value']['expose']['identifier'] = 'field_term_value';
  $handler->display->display_options['filters']['field_term_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p><strong>Learning about what data- or method-oriented courses are available should be simple.</strong> Because the Berkeley course offerings have limited search capabilities, D-Lab creates listings of Berkeley graduate and undergraduate courses each semester that cover methods, approaches, techniques, tools, software, or data relevant to data-intensive social science across departments and disciplines. We anticipate adding course listings for online courses and other resources. After searching, click on the course title for additional details. Feedback? Please send to <a href="mailto:dlab@berkeley.edu">dlab@berkeley.edu</a>.<br /><br /></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: CCN */
  $handler->display->display_options['fields']['field_ccn']['id'] = 'field_ccn';
  $handler->display->display_options['fields']['field_ccn']['table'] = 'field_data_field_ccn';
  $handler->display->display_options['fields']['field_ccn']['field'] = 'field_ccn';
  $handler->display->display_options['fields']['field_ccn']['exclude'] = TRUE;
  /* Field: Content: Department */
  $handler->display->display_options['fields']['field_department']['id'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['table'] = 'field_data_field_department';
  $handler->display->display_options['fields']['field_department']['field'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_department']['alter']['path'] = 'course-by-department/[field_department]';
  $handler->display->display_options['fields']['field_department']['element_class'] = 'course-list-department';
  $handler->display->display_options['fields']['field_department']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Term (SP for Spring; FL for Fall) */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['label'] = '';
  $handler->display->display_options['fields']['field_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term']['element_label_colon'] = FALSE;
  /* Field: Content: Course Number */
  $handler->display->display_options['fields']['field_course_code_text']['id'] = 'field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['table'] = 'field_data_field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['field'] = 'field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['label'] = 'Course';
  $handler->display->display_options['fields']['field_course_code_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_code_text']['alter']['text'] = '[field_department]<br>[field_course_code_text]<br>';
  $handler->display->display_options['fields']['field_course_code_text']['alter']['make_link'] = TRUE;
  /* Field: Content: Instructor */
  $handler->display->display_options['fields']['field_instructor']['id'] = 'field_instructor';
  $handler->display->display_options['fields']['field_instructor']['table'] = 'field_data_field_instructor';
  $handler->display->display_options['fields']['field_instructor']['field'] = 'field_instructor';
  $handler->display->display_options['fields']['field_instructor']['label'] = '';
  $handler->display->display_options['fields']['field_instructor']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_instructor']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'http://osoc.berkeley.edu/OSOC/osoc?p_ccn=[field_ccn]&p_term=[field_term]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: course_number */
  $handler->display->display_options['fields']['field_course_number']['id'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['fields']['field_course_number']['field'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['label'] = 'number';
  $handler->display->display_options['fields']['field_course_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '<br>[field_description]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'course' => 'course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Dept';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Semester (field_semester) */
  $handler->display->display_options['filters']['field_semester_value']['id'] = 'field_semester_value';
  $handler->display->display_options['filters']['field_semester_value']['table'] = 'field_data_field_semester';
  $handler->display->display_options['filters']['field_semester_value']['field'] = 'field_semester_value';
  $handler->display->display_options['filters']['field_semester_value']['value'] = array(
    'Spring 2014' => 'Spring 2014',
  );
  $handler->display->display_options['filters']['field_semester_value']['group'] = 1;
  $handler->display->display_options['filters']['field_semester_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_semester_value']['expose']['operator_id'] = 'field_semester_value_op';
  $handler->display->display_options['filters']['field_semester_value']['expose']['label'] = 'Semester';
  $handler->display->display_options['filters']['field_semester_value']['expose']['operator'] = 'field_semester_value_op';
  $handler->display->display_options['filters']['field_semester_value']['expose']['identifier'] = 'field_semester_value';
  $handler->display->display_options['filters']['field_semester_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_semester_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Description (field_description) */
  $handler->display->display_options['filters']['field_description_value']['id'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['table'] = 'field_data_field_description';
  $handler->display->display_options['filters']['field_description_value']['field'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_description_value']['group'] = 1;
  $handler->display->display_options['filters']['field_description_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_description_value']['expose']['operator_id'] = 'field_description_value_op';
  $handler->display->display_options['filters']['field_description_value']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['field_description_value']['expose']['operator'] = 'field_description_value_op';
  $handler->display->display_options['filters']['field_description_value']['expose']['identifier'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'course-list';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: CCN */
  $handler->display->display_options['fields']['field_ccn']['id'] = 'field_ccn';
  $handler->display->display_options['fields']['field_ccn']['table'] = 'field_data_field_ccn';
  $handler->display->display_options['fields']['field_ccn']['field'] = 'field_ccn';
  $handler->display->display_options['fields']['field_ccn']['exclude'] = TRUE;
  /* Field: Content: Units */
  $handler->display->display_options['fields']['field_units']['id'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['table'] = 'field_data_field_units';
  $handler->display->display_options['fields']['field_units']['field'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['exclude'] = TRUE;
  /* Field: Content: Department */
  $handler->display->display_options['fields']['field_department']['id'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['table'] = 'field_data_field_department';
  $handler->display->display_options['fields']['field_department']['field'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_department']['alter']['path'] = 'course-by-department/[field_department]';
  $handler->display->display_options['fields']['field_department']['element_class'] = 'course-list-department';
  $handler->display->display_options['fields']['field_department']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Term (SP for Spring; FL for Fall) */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['label'] = '';
  $handler->display->display_options['fields']['field_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term']['element_label_colon'] = FALSE;
  /* Field: Content: Course Number */
  $handler->display->display_options['fields']['field_course_code_text']['id'] = 'field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['table'] = 'field_data_field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['field'] = 'field_course_code_text';
  $handler->display->display_options['fields']['field_course_code_text']['label'] = 'Course';
  $handler->display->display_options['fields']['field_course_code_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_code_text']['alter']['text'] = '[field_department]<br>[field_course_code_text]<br>[field_units] units';
  $handler->display->display_options['fields']['field_course_code_text']['alter']['make_link'] = TRUE;
  /* Field: Content: Instructor */
  $handler->display->display_options['fields']['field_instructor']['id'] = 'field_instructor';
  $handler->display->display_options['fields']['field_instructor']['table'] = 'field_data_field_instructor';
  $handler->display->display_options['fields']['field_instructor']['field'] = 'field_instructor';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['path'] = 'http://osoc.berkeley.edu/OSOC/osoc?p_ccn=[field_ccn]&p_term=[field_term]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: course_number */
  $handler->display->display_options['fields']['field_course_number']['id'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['fields']['field_course_number']['field'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['label'] = 'number';
  $handler->display->display_options['fields']['field_course_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '<br>[field_description]';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'course::field_semester' => 'course::field_semester',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_remove_canceled_users_from_count' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_send_feedback_email_part_1' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_send_feedback_email_part_2' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_reminder_email_1' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_reminder_email_2' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Semester */
  $handler->display->display_options['fields']['field_semester']['id'] = 'field_semester';
  $handler->display->display_options['fields']['field_semester']['table'] = 'field_data_field_semester';
  $handler->display->display_options['fields']['field_semester']['field'] = 'field_semester';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Feeds item: Import date */
  $handler->display->display_options['sorts']['imported']['id'] = 'imported';
  $handler->display->display_options['sorts']['imported']['table'] = 'feeds_item';
  $handler->display->display_options['sorts']['imported']['field'] = 'imported';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Department (field_department) */
  $handler->display->display_options['sorts']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['sorts']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['sorts']['field_department_tid']['field'] = 'field_department_tid';
  /* Sort criterion: Content: course_number (field_course_number) */
  $handler->display->display_options['sorts']['field_course_number_value']['id'] = 'field_course_number_value';
  $handler->display->display_options['sorts']['field_course_number_value']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['sorts']['field_course_number_value']['field'] = 'field_course_number_value';
  /* Sort criterion: Content: Course Number (field_course_code_text) */
  $handler->display->display_options['sorts']['field_course_code_text_value']['id'] = 'field_course_code_text_value';
  $handler->display->display_options['sorts']['field_course_code_text_value']['table'] = 'field_data_field_course_code_text';
  $handler->display->display_options['sorts']['field_course_code_text_value']['field'] = 'field_course_code_text_value';
  /* Sort criterion: Content: CCN (field_ccn) */
  $handler->display->display_options['sorts']['field_ccn_value']['id'] = 'field_ccn_value';
  $handler->display->display_options['sorts']['field_ccn_value']['table'] = 'field_data_field_ccn';
  $handler->display->display_options['sorts']['field_ccn_value']['field'] = 'field_ccn_value';
  /* Sort criterion: Content: Units (field_units) */
  $handler->display->display_options['sorts']['field_units_value']['id'] = 'field_units_value';
  $handler->display->display_options['sorts']['field_units_value']['table'] = 'field_data_field_units';
  $handler->display->display_options['sorts']['field_units_value']['field'] = 'field_units_value';
  $handler->display->display_options['sorts']['field_units_value']['order'] = 'DESC';
  /* Sort criterion: Content: Semester (field_semester) */
  $handler->display->display_options['sorts']['field_semester_value']['id'] = 'field_semester_value';
  $handler->display->display_options['sorts']['field_semester_value']['table'] = 'field_data_field_semester';
  $handler->display->display_options['sorts']['field_semester_value']['field'] = 'field_semester_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Dept';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Description (field_description) */
  $handler->display->display_options['filters']['field_description_value']['id'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['table'] = 'field_data_field_description';
  $handler->display->display_options['filters']['field_description_value']['field'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_description_value']['group'] = 1;
  $handler->display->display_options['filters']['field_description_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_description_value']['expose']['operator_id'] = 'field_description_value_op';
  $handler->display->display_options['filters']['field_description_value']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['field_description_value']['expose']['operator'] = 'field_description_value_op';
  $handler->display->display_options['filters']['field_description_value']['expose']['identifier'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Semester (field_semester) */
  $handler->display->display_options['filters']['field_semester_value']['id'] = 'field_semester_value';
  $handler->display->display_options['filters']['field_semester_value']['table'] = 'field_data_field_semester';
  $handler->display->display_options['filters']['field_semester_value']['field'] = 'field_semester_value';
  $handler->display->display_options['filters']['field_semester_value']['value'] = array(
    'Spring 2014' => 'Spring 2014',
  );
  $handler->display->display_options['filters']['field_semester_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_semester_value']['expose']['operator_id'] = 'field_semester_value_op';
  $handler->display->display_options['filters']['field_semester_value']['expose']['label'] = 'Semester (field_semester)';
  $handler->display->display_options['filters']['field_semester_value']['expose']['operator'] = 'field_semester_value_op';
  $handler->display->display_options['filters']['field_semester_value']['expose']['identifier'] = 'field_semester_value';
  $handler->display->display_options['filters']['field_semester_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Term (SP for Spring; FL for Fall) (field_term) */
  $handler->display->display_options['filters']['field_term_value']['id'] = 'field_term_value';
  $handler->display->display_options['filters']['field_term_value']['table'] = 'field_data_field_term';
  $handler->display->display_options['filters']['field_term_value']['field'] = 'field_term_value';
  $handler->display->display_options['filters']['field_term_value']['value'] = 'SP';
  $handler->display->display_options['filters']['field_term_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_value']['expose']['operator_id'] = 'field_term_value_op';
  $handler->display->display_options['filters']['field_term_value']['expose']['label'] = 'Term (SP for Spring; FL for Fall) (field_term)';
  $handler->display->display_options['filters']['field_term_value']['expose']['operator'] = 'field_term_value_op';
  $handler->display->display_options['filters']['field_term_value']['expose']['identifier'] = 'field_term_value';
  $handler->display->display_options['filters']['field_term_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'bulk';
  $export['course_list'] = $view;

  return $export;
}
