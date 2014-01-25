<?php

class Xpl_Admin_Page extends WP_Plugin_Admin_Page {	
	
	public $columns = array(
		'Function',
		'Parameters',
		'Description',
	);
	
	public $functions = array();
	
	function init(){
		$this->functions = xpl_get_defined_functions();
		$this->constants = xpl_get_defined_constants();
		$this->classes = xpl_get_defined_classes();
	}
	
	function _section_after_form(){
		?>
		<div class="clearfix"></div>
		<br>
		<table class="widefat">
		<thead><tr><th>Constant</th><th>Value</th></tr></thead>
			<tbody>
			<tr><td colspan="2"><strong><em>Core</em></strong></td></tr>
			<?php foreach($this->constants['core'] as $constant){
				
				echo '<tr><td><b>' . $constant . '</b></td>';
				echo '<td>' . constant($constant) . '</td></tr>';
				
			} ?>
			<tr><td colspan="2"><strong><em>User</em></strong></td></tr>
			<?php foreach($this->constants['user'] as $constant){
				
				echo '<tr><td><b>' . $constant . '</b></td>';
				echo '<td>' . constant($constant) . '</td></tr>';
				
			} ?>
			</tbody>
		</table>
		
		<?php
	}
		
	function setting_preview( $function ){

	}
	
}

