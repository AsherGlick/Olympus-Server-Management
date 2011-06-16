<?php if($_POST['retrieve'] == "serverlist"): ?>
				<li><a href="#" id="server_1234" onclick="show_plugins(1234)">Server</a> - <span class="italics">128.67.224.101</span></li>
				<li><a href="#" id="server_1000" onclick="show_plugins(1000)">Server</a> - <span class="italics">128.67.224.101</span></li>
				<li><a href="#" id="server_1200" onclick="show_plugins(1200)">Server</a> - <span class="italics">128.67.224.101</span></li>
				<li><a href="#" id="server_1300" onclick="show_plugins(1300)">Server</a> - <span class="italics">128.67.224.101</span></li>
				<li><a href="#" id="server_1400" onclick="show_plugins(1400)">Server</a> - <span class="italics">128.67.224.101</span></li>
<?php elseif($_POST['retrieve'] == "plugins" && $_POST['id']): ?>
	<h3>Plugins for Server <?php echo $_POST['id']; ?></h3>	
	<!--PLUGINS GRID-->
	<div class="plugin_container_base" id="plugin_1">
		<a href="#" onclick="open_dialog(1)" ><img src="plugins/test_img.png"></a>
	</div>

	<div class="plugin_container_base" id="plugin_2">
		<a href="#" onclick="open_dialog(2)" >Plugin2</a>
	</div>
	
	<div class="plugin_container_base" id="plugin_3">
		<a href="#" onclick="open_dialog(3)" >Plugin3</a>
	</div>	

	<div class="plugin_container_base" id="plugin_4">
		<a href="#" onclick="open_dialog(4)" ><img src="plugins/test_img.png"></a>
	</div>

	<div class="plugin_container_base" id="plugin_5">
		<a href="#" onclick="open_dialog(5)" >Plugin5</a>
	</div>
	
	<div class="plugin_container_base" id="plugin_6">
		<a href="#" onclick="open_dialog(6)" >Plugin6</a>
	</div>
	
	<div class="plugin_container_base" id="plugin_7">
		<a href="#" onclick="open_dialog(7)" >Plugin7</a>
	</div>		
	
	<div class="plugin_container_base" id="plugin_8">
		<a href="#" onclick="open_dialog(8)" >Plugin8</a>
	</div>						
	<div class="clear"></div>
	<!--END PLUGINS GRID-->
	
	<!--PLUGINS-->
	<div id="plugin_1_dialog" class="dlg" title="Plugin 1">
Quisque elit augue, posuere vel adipiscing in, suscipit vitae erat. Vivamus sit amet dolor turpis, non aliquet felis. Nam turpis orci, ultricies nec posuere placerat, accumsan consectetur tortor. Pellentesque tristique bibendum odio et suscipit. Donec placerat lacus at nisi tincidunt eu tempus metus hendrerit. Nullam imperdiet, nisi vel ornare faucibus, lorem diam tempor orci, molestie egestas mauris diam quis ipsum. Curabitur auctor adipiscing nunc ornare egestas. Nulla facilisi. Maecenas felis sem, pharetra in euismod in, fringilla vitae justo. Maecenas facilisis tincidunt vulputate. Maecenas semper augue eget ipsum ornare ac suscipit arcu vestibulum. Vivamus facilisis, enim non feugiat interdum, justo dolor pellentesque tellus, et eleifend mi ante vel lectus. Fusce nec nisi in tortor adipiscing accumsan ut vel ipsum. Mauris et erat erat, eu pellentesque erat. Aliquam urna risus, rutrum id facilisis et, volutpat quis felis. Vivamus molestie pharetra sollicitudin. Praesent id neque dui. Cras eu dolor massa. 
	</div>	
	<script type="text/javascript">
		$('#plugin_1_dialog').dialog({ 
			autoOpen: false, 
			show: "scale",
			width:300,
			height:300,
			maxWidth: 500,
			maxHeight: 500,
			scroll: true,
			position: [0,0],
		});
	</script>
	
	<div id="plugin_2_dialog" class="dlg" title="Plugin 2">
		plugin 1 dialog
	</div>	
	<script type="text/javascript">
		$('#plugin_2_dialog').dialog({ 
			autoOpen: false, 
			show: "scale",
			width:300,
			height:300,
			maxWidth: 500,
			maxHeight: 500,
			scroll: true,
			position: [300,0],
			});
	</script>
	
	<div id="plugin_3_dialog" class="dlg" title="Plugin 3">
		plugin 1 dialog
	</div>	
	<script type="text/javascript">
		$('#plugin_3_dialog').dialog({ 
			autoOpen: false, 
			show: "scale",
			width:300,
			height:300,
			maxWidth: 500,
			maxHeight: 500,
			scroll: true,
			position: [600,0],			
			});
	</script>

	<div id="plugin_4_dialog" class="dlg" title="Plugin 4">
Quisque elit augue, posuere vel adipiscing in, suscipit vitae erat. Vivamus sit amet dolor turpis, non aliquet felis. Nam turpis orci, ultricies nec posuere placerat, accumsan consectetur tortor. Pellentesque tristique bibendum odio et suscipit. Donec placerat lacus at nisi tincidunt eu tempus metus hendrerit. Nullam imperdiet, nisi vel ornare faucibus, lorem diam tempor orci, molestie egestas mauris diam quis ipsum. Curabitur auctor adipiscing nunc ornare egestas. Nulla facilisi. Maecenas felis sem, pharetra in euismod in, fringilla vitae justo. Maecenas facilisis tincidunt vulputate. Maecenas semper augue eget ipsum ornare ac suscipit arcu vestibulum. Vivamus facilisis, enim non feugiat interdum, justo dolor pellentesque tellus, et eleifend mi ante vel lectus. Fusce nec nisi in tortor adipiscing accumsan ut vel ipsum. Mauris et erat erat, eu pellentesque erat. Aliquam urna risus, rutrum id facilisis et, volutpat quis felis. Vivamus molestie pharetra sollicitudin. Praesent id neque dui. Cras eu dolor massa. 
	</div>	
	<script type="text/javascript">
		$('#plugin_4_dialog').dialog({ 
			autoOpen: false, 
			show: "scale",
			width:300,
			height:300,
			maxWidth: 500,
			maxHeight: 500,
			scroll: true,
			position: [0,300],
			});
	</script>	

	<div id="plugin_5_dialog" class="dlg" title="Plugin 5">
Quisque elit augue, posuere vel adipiscing in, suscipit vitae erat. Vivamus sit amet dolor turpis, non aliquet felis. Nam turpis orci, ultricies nec posuere placerat, accumsan consectetur tortor. Pellentesque tristique bibendum odio et suscipit. Donec placerat lacus at nisi tincidunt eu tempus metus hendrerit. Nullam imperdiet, nisi vel ornare faucibus, lorem diam tempor orci, molestie egestas mauris diam quis ipsum. Curabitur auctor adipiscing nunc ornare egestas. Nulla facilisi. Maecenas felis sem, pharetra in euismod in, fringilla vitae justo. Maecenas facilisis tincidunt vulputate. Maecenas semper augue eget ipsum ornare ac suscipit arcu vestibulum. Vivamus facilisis, enim non feugiat interdum, justo dolor pellentesque tellus, et eleifend mi ante vel lectus. Fusce nec nisi in tortor adipiscing accumsan ut vel ipsum. Mauris et erat erat, eu pellentesque erat. Aliquam urna risus, rutrum id facilisis et, volutpat quis felis. Vivamus molestie pharetra sollicitudin. Praesent id neque dui. Cras eu dolor massa. 
	</div>	
	<script type="text/javascript">
		$('#plugin_5_dialog').dialog({ 
			autoOpen: false, 
			show: "scale",
			width:300,
			height:300,
			maxWidth: 500,
			maxHeight: 500,
			scroll: true,
			position: [300,300],
			});
	</script>	
	
	<div id="plugin_6_dialog" class="dlg" title="Plugin 6">
Quisque elit augue, posuere vel adipiscing in, suscipit vitae erat. Vivamus sit amet dolor turpis, non aliquet felis. Nam turpis orci, ultricies nec posuere placerat, accumsan consectetur tortor. Pellentesque tristique bibendum odio et suscipit. Donec placerat lacus at nisi tincidunt eu tempus metus hendrerit. Nullam imperdiet, nisi vel ornare faucibus, lorem diam tempor orci, molestie egestas mauris diam quis ipsum. Curabitur auctor adipiscing nunc ornare egestas. Nulla facilisi. Maecenas felis sem, pharetra in euismod in, fringilla vitae justo. Maecenas facilisis tincidunt vulputate. Maecenas semper augue eget ipsum ornare ac suscipit arcu vestibulum. Vivamus facilisis, enim non feugiat interdum, justo dolor pellentesque tellus, et eleifend mi ante vel lectus. Fusce nec nisi in tortor adipiscing accumsan ut vel ipsum. Mauris et erat erat, eu pellentesque erat. Aliquam urna risus, rutrum id facilisis et, volutpat quis felis. Vivamus molestie pharetra sollicitudin. Praesent id neque dui. Cras eu dolor massa. 
	</div>	
	<script type="text/javascript">
		$('#plugin_6_dialog').dialog({ 
			autoOpen: false, 
			show: "scale",
			width:300,
			height:300,
			maxWidth: 500,
			maxHeight: 500,
			scroll: true,
			position: [600,300],
			});
	</script>
	
	<div id="plugin_7_dialog" class="dlg" title="Plugin 7">
Quisque elit augue, posuere vel adipiscing in, suscipit vitae erat. Vivamus sit amet dolor turpis, non aliquet felis. Nam turpis orci, ultricies nec posuere placerat, accumsan consectetur tortor. Pellentesque tristique bibendum odio et suscipit. Donec placerat lacus at nisi tincidunt eu tempus metus hendrerit. Nullam imperdiet, nisi vel ornare faucibus, lorem diam tempor orci, molestie egestas mauris diam quis ipsum. Curabitur auctor adipiscing nunc ornare egestas. Nulla facilisi. Maecenas felis sem, pharetra in euismod in, fringilla vitae justo. Maecenas facilisis tincidunt vulputate. Maecenas semper augue eget ipsum ornare ac suscipit arcu vestibulum. Vivamus facilisis, enim non feugiat interdum, justo dolor pellentesque tellus, et eleifend mi ante vel lectus. Fusce nec nisi in tortor adipiscing accumsan ut vel ipsum. Mauris et erat erat, eu pellentesque erat. Aliquam urna risus, rutrum id facilisis et, volutpat quis felis. Vivamus molestie pharetra sollicitudin. Praesent id neque dui. Cras eu dolor massa. 
	</div>	
	<script type="text/javascript">
		$('#plugin_7_dialog').dialog({ 
			autoOpen: false, 
			show: "scale",
			width:300,
			height:300,
			maxWidth: 500,
			maxHeight: 500,
			scroll: true,
			position: [0,0],
			});
	</script>	

	<div id="plugin_8_dialog" class="dlg" title="Plugin 8">
Quisque elit augue, posuere vel adipiscing in, suscipit vitae erat. Vivamus sit amet dolor turpis, non aliquet felis. Nam turpis orci, ultricies nec posuere placerat, accumsan consectetur tortor. Pellentesque tristique bibendum odio et suscipit. Donec placerat lacus at nisi tincidunt eu tempus metus hendrerit. Nullam imperdiet, nisi vel ornare faucibus, lorem diam tempor orci, molestie egestas mauris diam quis ipsum. Curabitur auctor adipiscing nunc ornare egestas. Nulla facilisi. Maecenas felis sem, pharetra in euismod in, fringilla vitae justo. Maecenas facilisis tincidunt vulputate. Maecenas semper augue eget ipsum ornare ac suscipit arcu vestibulum. Vivamus facilisis, enim non feugiat interdum, justo dolor pellentesque tellus, et eleifend mi ante vel lectus. Fusce nec nisi in tortor adipiscing accumsan ut vel ipsum. Mauris et erat erat, eu pellentesque erat. Aliquam urna risus, rutrum id facilisis et, volutpat quis felis. Vivamus molestie pharetra sollicitudin. Praesent id neque dui. Cras eu dolor massa. 
	</div>	
	<script type="text/javascript">
		$('#plugin_8_dialog').dialog({ 
			autoOpen: false, 
			show: "scale",
			width:300,
			height:300,
			maxWidth: 500,
			maxHeight: 500,
			scroll: true,
			position: [0,0],
			});
	</script>				
	<!--END PLUGINS-->
	<script type="text/javascript">
		$('.dlg').dialog().parents('.ui-dialog').draggable('option', 'snap',true);	
		$('.dlg').dialog().parents('.ui-dialog').draggable('option', 'grid',[30,30]);			
	</script>
<?php elseif($_POST['retrieve'] == "day"): ?>
	There are no installed global plugins
<?php endif; ?>