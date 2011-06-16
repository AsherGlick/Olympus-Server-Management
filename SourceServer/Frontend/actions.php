<?php if($_POST['retrieve'] == "serverlist"): ?>
				<li><a href="#" id="server_1234" onclick="show_plugins(1234)">Server</a> - <span class="italics">128.67.224.101</span></li>
				<li><a href="#" id="server_1000" onclick="show_plugins(1000)">Server</a> - <span class="italics">128.67.224.101</span></li>
				<li><a href="#" id="server_1200" onclick="show_plugins(1200)">Server</a> - <span class="italics">128.67.224.101</span></li>
				<li><a href="#" id="server_1300" onclick="show_plugins(1300)">Server</a> - <span class="italics">128.67.224.101</span></li>
				<li><a href="#" id="server_1400" onclick="show_plugins(1400)">Server</a> - <span class="italics">128.67.224.101</span></li>
<?php elseif($_POST['retrieve'] == "plugins" && $_POST['id']): ?>
	<h3>Plugins for Server <?php echo $_POST['id']; ?></h3>
	<p>Plugin1</p>
	<p>Plugin2</p>			
<?php elseif($_POST['retrieve'] == "day"): ?>
	thursday
<?php endif; ?>