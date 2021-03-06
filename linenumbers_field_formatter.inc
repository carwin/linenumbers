<?php

/**
 * @file
 * Linenumbers core functions.
 */

/**
 * Implements hook_help().
 */
function linenumbers_help($path, $arg) {
  switch ($path) {
    case 'admin/help#linenumbers':
      $output = '';
      $output .= '<h3>' . t('About') . '</h3>';
      $output .= '<p>' . t('Linenumbers creates a field formatter for adding line numbers to Long Text fields. Currently, Nodelines strips html tags from field input and wraps everyting in <code>pre</code> tags, similar to the Plain Text formatter. Plans for development include removing this function to allow html elements to be output with line numbers.') . '</p><p>It is recommended to disable the line break filter when using this module.</p>';
      return $output;
  }
}

/**
 * Implements hook_field_formatter_info().
 */
function linenumbers_field_formatter_info() {
  return array(
    'linenumbers' => array(
      'label' => t('Linenumbers'),
      'field types' => array('text_long', 'text_with_summary'),
      'settings' => array(
        'html_wrapper' => 'pre',
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function linenumbers_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $settings = $display['settings'];
  $lines = substr_count($items[0]['value'], '\n');
  switch ($display['type']) {
    case 'linenumbers':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => strip_tags($item['value']));
        $lines_arr = preg_split('/\n/', $element[$delta]['#markup']);
        $i = 1;

        // Start the html wrapper from the settings form.
        if ($settings['html_wrapper'] != 'code') {
          $element[$delta]['#markup'] = '<' . $settings['html_wrapper'] . '>';
        }

        // If <code> is chosen in the settings, each line needs to be wrapped,
        // which means that #markup needs to be emptied so it can be
        // reformatted line by line.
        else {
          $element[$delta]['#markup'] = '';
        }

        // Loop over each line in $line_arr and prepend the line number to it.
        // If the code wrapper is chosen via settings, wrap each line in <code>
        foreach ($lines_arr as &$value) {
          if ($settings['html_wrapper'] == 'code') {
            $element[$delta]['#markup'] .= '<code>';
          }
          $value = $i . '| ' . $value;
          $element[$delta]['#markup'] .= $value;
          if ($settings['html_wrapper'] == 'code') {
            $element[$delta]['#markup'] .= '</code>';
          }

          $i++;
        }

        // Close up the html_wrapper.
        if ($settings['html_wrapper'] != 'code') {
          $element[$delta]['#markup'] .= '</' . $settings['html_wrapper'] . '>';
        }

      }
      break;
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function linenumbers_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {

  // Follow the format of the text module since it is similar.
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();
  if ($display['type'] == 'linenumbers') {

    // Set up available options for wrapping content.
    $element['html_wrapper'] = array(
      '#title' => t('HTML Wrapper'),
      '#type' => 'select',
      '#options' => array(
        'pre' => t('pre'),
        'code' => t('code'),
      ),
      '#default_value' => $settings['html_wrapper'],
    );
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function linenumbers_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = '';

  if ($display['type'] == 'linenumbers') {
    $summary = t('HTML wrapper: @html_wrapper', array(
      '@html_wrapper' => $settings['html_wrapper'],
    ));
  }

  return $summary;
}
