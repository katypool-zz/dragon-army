<?php
/**
 * @file
 * consultation_request.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function consultation_request_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'support_ticket_list';
  $view->description = 'moderator page for listing all support tickets (anything that came in through contact-us form)';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Support Tickets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Support Ticket List (Contact Us Form)';
  $handler->display->display_options['css_class'] = 'support-ticket-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'All tickets have been assigned! Yay!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Flags: status */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'status';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Ticket ID';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Subject';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Your email */
  $handler->display->display_options['fields']['field_ticket_user_email']['id'] = 'field_ticket_user_email';
  $handler->display->display_options['fields']['field_ticket_user_email']['table'] = 'field_data_field_ticket_user_email';
  $handler->display->display_options['fields']['field_ticket_user_email']['field'] = 'field_ticket_user_email';
  $handler->display->display_options['fields']['field_ticket_user_email']['label'] = 'Contact Email';
  /* Field: Content: Your name */
  $handler->display->display_options['fields']['field_ticket_user_name']['id'] = 'field_ticket_user_name';
  $handler->display->display_options['fields']['field_ticket_user_name']['table'] = 'field_data_field_ticket_user_name';
  $handler->display->display_options['fields']['field_ticket_user_name']['field'] = 'field_ticket_user_name';
  $handler->display->display_options['fields']['field_ticket_user_name']['label'] = 'Contact Name';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_ticket_status']['id'] = 'field_ticket_status';
  $handler->display->display_options['fields']['field_ticket_status']['table'] = 'field_data_field_ticket_status';
  $handler->display->display_options['fields']['field_ticket_status']['field'] = 'field_ticket_status';
  $handler->display->display_options['fields']['field_ticket_status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ticket_status']['alter']['text'] = '<div class="[field_ticket_status] views-field">[field_ticket_status]</div>';
  $handler->display->display_options['fields']['field_ticket_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Assigned Staff Member */
  $handler->display->display_options['fields']['field_assigned_staff_member']['id'] = 'field_assigned_staff_member';
  $handler->display->display_options['fields']['field_assigned_staff_member']['table'] = 'field_data_field_assigned_staff_member';
  $handler->display->display_options['fields']['field_assigned_staff_member']['field'] = 'field_assigned_staff_member';
  $handler->display->display_options['fields']['field_assigned_staff_member']['empty'] = '<a href="../support-ticket-list/assign/[nid]">Assign this ticket</a>';
  /* Sort criterion: Content: Status (field_ticket_status) */
  $handler->display->display_options['sorts']['field_ticket_status_tid']['id'] = 'field_ticket_status_tid';
  $handler->display->display_options['sorts']['field_ticket_status_tid']['table'] = 'field_data_field_ticket_status';
  $handler->display->display_options['sorts']['field_ticket_status_tid']['field'] = 'field_ticket_status_tid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'support_ticket' => 'support_ticket',
  );
  /* Filter criterion: Content: Status (field_ticket_status) */
  $handler->display->display_options['filters']['field_ticket_status_tid']['id'] = 'field_ticket_status_tid';
  $handler->display->display_options['filters']['field_ticket_status_tid']['table'] = 'field_data_field_ticket_status';
  $handler->display->display_options['filters']['field_ticket_status_tid']['field'] = 'field_ticket_status_tid';
  $handler->display->display_options['filters']['field_ticket_status_tid']['value'] = array(
    98 => '98',
  );
  $handler->display->display_options['filters']['field_ticket_status_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ticket_status_tid']['expose']['operator_id'] = 'field_ticket_status_tid_op';
  $handler->display->display_options['filters']['field_ticket_status_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_ticket_status_tid']['expose']['operator'] = 'field_ticket_status_tid_op';
  $handler->display->display_options['filters']['field_ticket_status_tid']['expose']['identifier'] = 'field_ticket_status_tid';
  $handler->display->display_options['filters']['field_ticket_status_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_ticket_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ticket_status_tid']['vocabulary'] = 'support_ticket_status';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Subject, Message, Name, Email';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_ticket_user_email' => 'field_ticket_user_email',
    'field_ticket_user_name' => 'field_ticket_user_name',
    'body' => 'body',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Ticket ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<script>
jQuery(\'span.username:contains("Anonymous (not verified)")\').text(\'NONE\');

jQuery(\'.views-field-comment-count\').each( function () {
            var comment_count = parseInt(jQuery(this).text());
            if (comment_count > 0) {
                    jQuery(this).parent().find(\'.unresolved\').css(\'background\',\'#FFEC8B\');
                }
            });

</script>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'support-ticket-list';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Ticket ID';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Subject';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Your email */
  $handler->display->display_options['fields']['field_ticket_user_email']['id'] = 'field_ticket_user_email';
  $handler->display->display_options['fields']['field_ticket_user_email']['table'] = 'field_data_field_ticket_user_email';
  $handler->display->display_options['fields']['field_ticket_user_email']['field'] = 'field_ticket_user_email';
  $handler->display->display_options['fields']['field_ticket_user_email']['label'] = 'Contact Email';
  /* Field: Content: Your name */
  $handler->display->display_options['fields']['field_ticket_user_name']['id'] = 'field_ticket_user_name';
  $handler->display->display_options['fields']['field_ticket_user_name']['table'] = 'field_data_field_ticket_user_name';
  $handler->display->display_options['fields']['field_ticket_user_name']['field'] = 'field_ticket_user_name';
  $handler->display->display_options['fields']['field_ticket_user_name']['label'] = 'Contact Name';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Last comment author */
  $handler->display->display_options['fields']['last_comment_name']['id'] = 'last_comment_name';
  $handler->display->display_options['fields']['last_comment_name']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_comment_name']['field'] = 'last_comment_name';
  $handler->display->display_options['fields']['last_comment_name']['label'] = 'Last Staff Member to Respond';
  $handler->display->display_options['fields']['last_comment_name']['empty'] = 'NONE';
  $handler->display->display_options['fields']['last_comment_name']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['last_comment_name']['hide_alter_empty'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Staff Responses';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_ticket_status']['id'] = 'field_ticket_status';
  $handler->display->display_options['fields']['field_ticket_status']['table'] = 'field_data_field_ticket_status';
  $handler->display->display_options['fields']['field_ticket_status']['field'] = 'field_ticket_status';
  $handler->display->display_options['fields']['field_ticket_status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ticket_status']['alter']['text'] = '<div class="[field_ticket_status] views-field">[field_ticket_status]</div>';
  $handler->display->display_options['fields']['field_ticket_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['path'] = 'support-ticket-list/support-ticket-list.csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['support_ticket_list'] = $view;

  return $export;
}
