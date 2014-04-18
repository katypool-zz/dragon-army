<?php
/**
 * @file
 * reminder_emails.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function reminder_emails_default_rules_configuration() {
  $items = array();
  $items['rules_cron_training_3_day_reminder_emails'] = entity_import('rules_config', '{ "rules_cron_training_3_day_reminder_emails" : {
      "LABEL" : "Cron Training 3 Day Reminder Emails",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "views_bulk_operations", "rules" ],
      "ON" : { "cron" : [] },
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "rules_queue_72_hour_reminders|default" },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-list" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_send_3_day_reminder_email_part_1" : { "list_item" : [ "list_item" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_send_3_day_reminder_email_part_1'] = entity_import('rules_config', '{ "rules_send_3_day_reminder_email_part_1" : {
      "LABEL" : "Send 3 day reminder email part 1",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "list_item" : { "label" : "list_item", "type" : "node" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "list-item" ], "field" : "field_training_uid" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "nid",
              "value" : [ "list-item:field-training-uid:nid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "wkshp_node" : "wkshp-node" } }
          }
        },
        { "component_rules_send_3_day_reminder_email_part_2" : { "registrant" : [ "list-item" ], "workhop" : [ "wkshp-node:0" ] } }
      ]
    }
  }');
  $items['rules_send_3_day_reminder_email_part_2'] = entity_import('rules_config', '{ "rules_send_3_day_reminder_email_part_2" : {
      "LABEL" : "Send 3 day reminder email part 2",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "registrant" : { "label" : "registrant", "type" : "node" },
        "workhop" : { "label" : "workshop", "type" : "node" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "workhop" ], "field" : "field_date" } },
        { "entity_has_field" : { "entity" : [ "workhop" ], "field" : "field_traininglocation" } },
        { "entity_has_field" : { "entity" : [ "registrant" ], "field" : "field_three_day_boolean" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "date", "value" : [ "workhop:field-date" ] },
            "PROVIDE" : { "variable_added" : { "date" : "date" } }
          }
        },
        { "mail" : {
            "to" : "[registrant:field-registrant-email]",
            "subject" : "[D-Lab]: Reminder - [workhop:title] on [date:medium]",
            "message" : "Dear [registrant:title],\\r\\n\\r\\nThis is a reminder that the D-Lab [workhop:field_training_type]: [workhop:title] will begin [date:medium] in [workhop:field-traininglocation]. \\r\\n\\r\\nInformation about the [workhop:field_training_type] can be found at http:\\/\\/dlab.berkeley.edu\\/node\\/[workhop:nid]\\r\\n\\r\\n*If you previously received a registration confirmation:*\\r\\n\\r\\nYou are currently registered for the workshop and we look forward to seeing you there. Please note that seating is limited and there is a wait list of others who wish to attend. If you cannot attend, please hit \\u0022reply\\u0022 to this email and let us know. If you arrive late, your seat might also be given to someone on the wait list.\\r\\n\\r\\n*If you received a waitlist notification:*\\r\\n\\r\\nWe encourage you to show up. If seats are available, you will be admitted to the  [workhop:field_training_type] based on your position on the waitlist, which can be found in your waitlist notification email.\\r\\n\\r\\nPlease email dlabservices@berkeley.edu if you have questions.\\r\\n\\r\\nThanks,\\r\\nD-Lab",
            "from" : "dlabservices@berkeley.edu",
            "language" : [ "" ]
          }
        },
        { "data_set" : { "data" : [ "registrant:field-three-day-boolean" ], "value" : 1 } }
      ]
    }
  }');
  return $items;
}
