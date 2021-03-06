<?php
/**
 * @file
 * Defining our migration of petitions and signatures from MongoDB to Drupaly
 * (MySQL) objects (entities).
 */

/**
 * Implements hook_migrate_api().
 */
function migrate_mongo2mysql_petsig_migrate_api() {

  $api = array(
    'api' => 2,
    'groups' => array(
      'petsig' => array(
        'title' => t('Petition & Signature Imports'),
      ),
    ),
    'migrations' => array(
      'Petition' => array(
        'class_name' => 'PetitionMigration',
        'group_name' => 'petsig',
      ),
      'Signature' => array(
        'class_name' => 'SignatureMigration',
        'group_name' => 'petsig',
        'dependencies' => array('Petition'),
      ),
    ),
  );
  return $api;
}
