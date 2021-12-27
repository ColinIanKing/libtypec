/**
 * @file libtypec.h
 * @author Rajaram Regupathy
 * @brief 
 *      Public libtypec header file providing interfaces for USB Type-C 
 * Connector System Software.
 * 
 * @copyright 
 * Copyright (c) 2021 Rajaram Regupathy <rajaram.regupathy@gmail.com>
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 * 
 */

#ifndef LIBTYPEC_H
#define LIBTYPEC_H


struct libtypec_capabiliy_data
{
    unsigned int bmAttributes;
    unsigned bNumConnectors:7;
    unsigned reserved:1;
    unsigned bmOptionalFeatures:24;
    unsigned bNumAltModes:8;
    unsigned reserverd :8;
    unsigned bcdBCVersion:16;
    unsigned bcdPDVersion:16;
    unsigned bcdTypeCVersion:16;    
};

struct libtypec_connector_cap_data
{
    unsigned int opr_mode:8;
    unsigned provider:1;
    unsigned consumer:1;
    unsigned swap2dfp:1;
    unsigned swap2ufp:1;
    unsigned swap2src:1;
    unsigned swap2snk:1;
    unsigned reserved:1;
};

struct altmode_data {
	unsigned long svid;
	unsigned long vdo;
};


#define LIBTYPEC_MAJOR_VERSION 0
#define LIBTYPEC_MINOR_VERSION 1

#define LIBTYPEC_VERSION_INDEX 0
#define LIBTYPEC_KERNEL_INDEX 1
#define LIBTYPEC_CLASS_INDEX 2
#define LIBTYPEC_INTF_INDEX 3
#define LIBTYPEC_SESSION_MAX_INDEX 4


#define OPR_MODE_RP_ONLY 0
#define OPR_MODE_RD_ONLY 1
#define OPR_MODE_DRP_ONLY 2

#define AM_CONNECTOR 0
#define AM_SOP 1
#define AM_SOP_PR 2
#define AM_SOP_DPR 3

int libtypec_init(char **session_info);
int libtypec_exit(void);

/**
 * @brief 
 * 
 */
int libtypec_get_capability (struct libtypec_capabiliy_data *cap_data);
int libtypec_get_conn_capability (int conn_num, struct libtypec_connector_cap_data *conn_cap_data);
int libtypec_get_alternate_modes (int recipient, int conn_num, struct altmode_data *alt_mode_data);
int libtypec_get_cam_supported (int conn_num, char *cam_data);
int libtypec_get_current_cam (char *cur_cam_data);
int libtypec_get_pdos (int conn_num, int partner, int offset, int num_pdo, int src_snk, int type, char *pdo_data);
int libtypec_get_cable_properties (int conn_num, char *cbl_prop_data);
int libtypec_get_connector_status (int conn_num, char *conn_sts_data);


#endif /*LIBTYPEC_H*/