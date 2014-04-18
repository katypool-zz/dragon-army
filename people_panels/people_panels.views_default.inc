<?php
/**
 * @file
 * people_panels.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function people_panels_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'instructor_trainings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Instructor Trainings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Instructor Activity';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_trainer_target_id']['id'] = 'field_trainer_target_id';
  $handler->display->display_options['relationships']['field_trainer_target_id']['table'] = 'field_data_field_trainer';
  $handler->display->display_options['relationships']['field_trainer_target_id']['field'] = 'field_trainer_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_trainer_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'training' => 'training',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'instructor-trainings';

  /* Display: Trainings */
  $handler = $view->new_display('block', 'Trainings', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Trainings';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Trainings taught by this instructor';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'just_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_date']['delta_first_last'] = TRUE;
  $handler->display->display_options['fields']['field_date']['separator'] = ' - ';
  $handler->display->display_options['block_description'] = 'Trainings';

  /* Display: Consulting */
  $handler = $view->new_display('block', 'Consulting', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Consulting';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Consultation services offered by this person';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Schedule */
  $handler->display->display_options['fields']['field_schedule']['id'] = 'field_schedule';
  $handler->display->display_options['fields']['field_schedule']['table'] = 'field_data_field_schedule';
  $handler->display->display_options['fields']['field_schedule']['field'] = 'field_schedule';
  $handler->display->display_options['fields']['field_schedule']['label'] = '';
  $handler->display->display_options['fields']['field_schedule']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_schedule']['alter']['path'] = '%1';
  $handler->display->display_options['fields']['field_schedule']['element_label_colon'] = FALSE;
  /* Field: Content: Consulting Services */
  $handler->display->display_options['fields']['field_consulting_services']['id'] = 'field_consulting_services';
  $handler->display->display_options['fields']['field_consulting_services']['table'] = 'field_data_field_consulting_services';
  $handler->display->display_options['fields']['field_consulting_services']['field'] = 'field_consulting_services';
  $handler->display->display_options['fields']['field_consulting_services']['label'] = '';
  $handler->display->display_options['fields']['field_consulting_services']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_consulting_services']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_consulting_services']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'consultation' => 'consultation',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Consulting';

  /* Display: Working Groups */
  $handler = $view->new_display('block', 'Working Groups', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Working Groups';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Schedule */
  $handler->display->display_options['fields']['field_schedule']['id'] = 'field_schedule';
  $handler->display->display_options['fields']['field_schedule']['table'] = 'field_data_field_schedule';
  $handler->display->display_options['fields']['field_schedule']['field'] = 'field_schedule';
  $handler->display->display_options['fields']['field_schedule']['label'] = '';
  $handler->display->display_options['fields']['field_schedule']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'working_groups' => 'working_groups',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Working Groups';

  /* Display: Trainings */
  $handler = $view->new_display('panel_pane', 'Trainings', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Trainings';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'just_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_date']['delta_first_last'] = TRUE;
  $handler->display->display_options['fields']['field_date']['separator'] = ' - ';

  /* Display: Consulting */
  $handler = $view->new_display('panel_pane', 'Consulting', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Consulting';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Consulting Services */
  $handler->display->display_options['fields']['field_consulting_services']['id'] = 'field_consulting_services';
  $handler->display->display_options['fields']['field_consulting_services']['table'] = 'field_data_field_consulting_services';
  $handler->display->display_options['fields']['field_consulting_services']['field'] = 'field_consulting_services';
  $handler->display->display_options['fields']['field_consulting_services']['label'] = '';
  $handler->display->display_options['fields']['field_consulting_services']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_consulting_services']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_consulting_services']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_consulting_services']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_consulting_services']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_consulting_services']['delta_limit'] = '4';
  $handler->display->display_options['fields']['field_consulting_services']['delta_offset'] = '0';
  /* Field: Content: Schedule */
  $handler->display->display_options['fields']['field_schedule']['id'] = 'field_schedule';
  $handler->display->display_options['fields']['field_schedule']['table'] = 'field_data_field_schedule';
  $handler->display->display_options['fields']['field_schedule']['field'] = 'field_schedule';
  $handler->display->display_options['fields']['field_schedule']['label'] = '';
  $handler->display->display_options['fields']['field_schedule']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_schedule']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_schedule']['element_label_colon'] = FALSE;
  /* Field: Content: Active */
  $handler->display->display_options['fields']['field_staffactive_1']['id'] = 'field_staffactive_1';
  $handler->display->display_options['fields']['field_staffactive_1']['table'] = 'field_data_field_staffactive';
  $handler->display->display_options['fields']['field_staffactive_1']['field'] = 'field_staffactive';
  $handler->display->display_options['fields']['field_staffactive_1']['label'] = '';
  $handler->display->display_options['fields']['field_staffactive_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_staffactive_1']['alter']['text'] = '<a href="../node/[nid]">[field_consulting_services]</a>';
  $handler->display->display_options['fields']['field_staffactive_1']['alter']['path'] = '../node/[nid]';
  $handler->display->display_options['fields']['field_staffactive_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staffactive_1']['empty'] = '[field_consulting_services]';
  $handler->display->display_options['fields']['field_staffactive_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_staffactive_1']['type'] = 'list_key';
  /* Field: Content: Active */
  $handler->display->display_options['fields']['field_staffactive']['id'] = 'field_staffactive';
  $handler->display->display_options['fields']['field_staffactive']['table'] = 'field_data_field_staffactive';
  $handler->display->display_options['fields']['field_staffactive']['field'] = 'field_staffactive';
  $handler->display->display_options['fields']['field_staffactive']['label'] = '';
  $handler->display->display_options['fields']['field_staffactive']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_staffactive']['alter']['text'] = '[field_schedule]';
  $handler->display->display_options['fields']['field_staffactive']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staffactive']['empty'] = 'Not currently available.';
  $handler->display->display_options['fields']['field_staffactive']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_staffactive']['type'] = 'list_key';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'consultation' => 'consultation',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Working Groups */
  $handler = $view->new_display('panel_pane', 'Working Groups', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Working Groups';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Schedule */
  $handler->display->display_options['fields']['field_schedule']['id'] = 'field_schedule';
  $handler->display->display_options['fields']['field_schedule']['table'] = 'field_data_field_schedule';
  $handler->display->display_options['fields']['field_schedule']['field'] = 'field_schedule';
  $handler->display->display_options['fields']['field_schedule']['label'] = '';
  $handler->display->display_options['fields']['field_schedule']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule']['element_label_colon'] = FALSE;
  /* Field: Content: Active */
  $handler->display->display_options['fields']['field_staffactive_1']['id'] = 'field_staffactive_1';
  $handler->display->display_options['fields']['field_staffactive_1']['table'] = 'field_data_field_staffactive';
  $handler->display->display_options['fields']['field_staffactive_1']['field'] = 'field_staffactive';
  $handler->display->display_options['fields']['field_staffactive_1']['label'] = '';
  $handler->display->display_options['fields']['field_staffactive_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_staffactive_1']['alter']['text'] = '<a href=:".../node/[nid]">[title]</a>';
  $handler->display->display_options['fields']['field_staffactive_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staffactive_1']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_staffactive_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_staffactive_1']['type'] = 'list_key';
  /* Field: Content: Active */
  $handler->display->display_options['fields']['field_staffactive']['id'] = 'field_staffactive';
  $handler->display->display_options['fields']['field_staffactive']['table'] = 'field_data_field_staffactive';
  $handler->display->display_options['fields']['field_staffactive']['field'] = 'field_staffactive';
  $handler->display->display_options['fields']['field_staffactive']['label'] = '';
  $handler->display->display_options['fields']['field_staffactive']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_staffactive']['alter']['text'] = '[field_schedule]';
  $handler->display->display_options['fields']['field_staffactive']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staffactive']['empty'] = 'Not currently active';
  $handler->display->display_options['fields']['field_staffactive']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_staffactive']['type'] = 'list_key';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'working_groups' => 'working_groups',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $export['instructor_trainings'] = $view;

  return $export;
}
