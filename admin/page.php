<?php
// get the admin instance
$admin = WP_Plugin_Admin_Controller::instance('xpl');

// get/create the page instance
$page = $admin->admin_page();

// use tfoot in table
$page->use_table_footer();

// process changes, if any
$changed = $page->page_request();

function doc_comment_clean( $string ){
	return str_replace(array("\n","\t","\r"), ' ', str_replace(array('*','/'), '', $string));
}

?>
<div class="wrap">

	<div id="icon-options-general" class="icon32"><br /></div>
	
	<h2><?php echo $page->title; ?></h2>
	
	<div class="clear"></div>
	
	<?php echo url(); if ( is_array($changed) ) { ?>
		<div id="message" class="updated"><p><?php echo "<b>{$changed['key']}</b> changed to <b>{$changed['value']}</b>"; ?></p></div>
	<?php } ?>
	
	<?php $page->do_page_section('before_form'); ?>
	
	<form action="<?php echo $page->form_action; ?>" method="post">
		
		<?php wp_nonce_field($page->nonce_name); ?>
		
		<?php $page->do_page_section('before_table'); ?>
	
		<table id="all-plugins-table" class="widefat">
			
			<thead>
				<tr>
					<?php foreach( $page->columns as $col ){ ?>
						<th class="manage-column" scope="col"><?php echo $col; ?></th>
					<?php } ?>
				</tr>
			</thead>
			
			<?php if ( $page->use_tfoot ) : ?>
			<tfoot>
				<tr>
					<?php foreach( $page->columns as $col ){ ?>
						<th class="manage-column" scope="col"><?php echo $col; ?></th>
					<?php } ?>
				</tr>
			</tfoot>
			<?php endif; ?>
			
			<tbody class="plugins">
				
				<?php foreach( $page->functions as $group => $functions ) : 
					
					echo '<tr><td colspan="3"><strong><em>' . ucfirst($group) . '</em></strong></td></tr>';
					
					foreach($functions as $func) :
					
					$refl = new ReflectionFunction($func);
				?>
					
					<tr class="<?php echo $func; ?> active">
						
						<td class="plugin-title">
						
							<strong><?php echo $func; ?></strong>
							
						</td><!-- .plugin-title -->
						
						<td>
							<div class="row-actions-visible">
							<?php foreach($refl->getParameters() as $param){
									
									$name = $param->getName();
									
									echo '<strong>';
									
									if ( $param->isPassedByReference() ){
										echo '&';	
									}
									
									echo '$' . $name . '</strong>';
									
									if ( $param->isOptional() ){
										echo ' (optional)';
									}
									if ( $param->isDefaultValueAvailable() ){
										echo ' Default: ' . $param->getDefaultValue();	
									}
									
									echo '<br>';
								}
							?>
							</div>
						</td>
						<td class="column-description desc">
							<div class="plugin-description">
								<p><?php 
									$docComment = $refl->getDocComment();
								
									$docComment = doc_comment_clean($docComment); 
									
									if ( false !== ($pos = strpos($docComment, '@return')) ){
										
										$return = str_replace('@return', '', substr($docComment, $pos));
										
										echo '<b>Returns ' . $return . "</b>\n.";
										
										$docComment = substr($docComment, 0, $pos);
									}
									
									// remove param comments
									if ( false !== strpos($docComment, '@param') ){
										$docComment = substr($docComment, 0, strpos($docComment, '@param'));
									}
									
									echo $docComment;
									
								?></p>
							</div>
						</td>
						
					</tr>
				
				<?php endforeach; endforeach; ?>
				
				<?php foreach($page->classes['core'] as $class ) : 
					
					$reflect = new ReflectionClass($class); ?>
				
					<tr class="<?php echo $class; ?> active">
						
						<td class="plugin-title">
						
							<strong><?php echo $class; ?></strong>
							
							<?php if ( $parent = $reflect->getParentClass() ){
								echo '<br><em>Extends: <strong>' . $parent->getName() . '</strong></em>';	
							} ?>
							
						</td><!-- .plugin-title -->
						<td>
							<div class="row-actions-visible">
								<p><strong>Properties</strong><br>
								<?php 
									$vars = $reflect->getProperties();
									foreach($vars as $var){
										echo $var . '<br>';
									} 
								?>
								</p>
							</div>
						</td>
						<td class="column-description desc">
							<div class="plugin-description">
								<?php 
								
									$methods = $reflect->getMethods();
									
									foreach($methods as $method){
										
										$param_str = '';
										
										foreach($method->getParameters() as $param){
											
											if ( $param->isPassedByReference() )
												$param_str .= '&';	
											
											$param_str .= ' $' . $param->getName();
											
											if ( $param->isDefaultValueAvailable() ) {
												$default = $param->getDefaultValue();
												if ( is_string($default) ) $default = '"' . $default . '"';
												elseif ( true === $default ) $default = 'true';
												elseif ( false === $default ) $default = 'false';
												elseif ( null === $default ) $default = 'null';
												$param_str .= ' = ' . $default . '';
											}
											
											$param_str .= ', ';
										}
										
										if ($method->isPublic()){
											echo '<em><b>Public</b></em> ';	
										} elseif ( $method->isPrivate() ){
											echo '<em>Private</em> ';	
										} elseif ($method->isProtected()){
											echo '<em>Protected</em> ';	
										}
										
										if ( $method->isFinal() ){
											echo '<small>FINAL</small> ';
										}
										if ( $method->isAbstract() ){
											echo '<small>ABSTRACT</small> ';	
										}
										
										echo '<code><strong>' . $method->getName() . '</strong>(' . trim($param_str, ', ') . ');</code> ';
										
										echo doc_comment_clean( $method->getDocComment() );
										
										echo '<br>';
									}	
		
								?>
							</div>
						</td>
					
					</tr>
				
				<?php endforeach; ?>
				
			</tbody><!-- .plugins -->
		</table><!-- .widefat -->
	
		<?php $page->do_page_section('after_table'); ?>
	
	</form>
	
	<?php $page->do_page_section('after_form'); ?>
	
</div><!-- .wrap -->